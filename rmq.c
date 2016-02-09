/*  
 * Implementation of a simple range minimum query algorithm described in
 * S. Alstrup, C. Gavoille, H. Kaplan, T. Rauhe.
 * Nearest common ancestors: a survey and a new distributed algorithm,
 * In Proc. 14th annual ACM symposium on Parallel algorithms and architectures, 258-264, 2002.
 *
 * Copyright (C) 2005 Hideo Bannai (http://tlas.i.kyushu-u.ac.jp/~bannai/)
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <stdio.h>
#include <stdlib.h>

int VAL_LT(long long a, long long b) {
  return a <= b;
}

struct rmqinfo {
  int alen;     // length of original array
  long long * array;  // pointer to original array
  int ** sparse;
  int * block_min;
  int * labels;
};

/* clear the least significant x-1 bits */
static inline int clearbits(int n, int x){
  return((n >> x) << x);  
}

/* return floor of log n. assumes n > 0
 * uses __builtin_clz for GCC */
static inline int intlog2(int n){
#ifdef __GNUC__
  return(__builtin_clz(n)^31);
#else
  int res;
  for(res = 0; n > 0; n >>= 1, res++);
  return(res-1);
#endif
}

/*
 * return position of least significant set bit. assumes n > 0
 * uses __builtin_ctz for GCC */
static inline int lsbset (int n){
#ifdef __GNUC__
  return(__builtin_ctz(n));
#else
  int res = 0;
  while(n % 2 == 0){
    res++; n >>= 1;
  }
  return(res);
#endif
}

/*
 * Return the position in array which gives the minimum value
 * in the subarray a[x..y] using a naive algorithm.
 * When there are multiple positions with the same minimum value,
 * in the range, the smallest index is returned.
 */
int rm_query_naive(long long * a, int x, int y){
  int z, tmp;
  long long minval;
  if(x == y) return x;
  if(x > y){
    tmp = x; x = y; y = tmp;
  }
  z = x;
  minval = a[x];  
  for(x++; x <= y; x++){
    if(VAL_LT(a[x],minval)){
      z = x; minval = a[x];
    }
  }
  return(z);
}

/*
 * Preprocess array in linear time so that range minimum
 * queries can be conducted in constant time.
 */
struct rmqinfo * rm_query_preprocess(long long * array, int alen){
  struct rmqinfo * info;
  int i, j, g, rows, cols, block_cnt, rowelmlen;
  int * block_min, **sparse, *labels;
  int gstack[32], gstacksize = 0;
  
  info = (struct rmqinfo *) malloc(sizeof(struct rmqinfo));
  /* divide input array into blocks of size 32.
   * block_cnt is the number of such blocks.
   * block_minpos is an array that contains the 
   * minimum positions in each block. */
  block_cnt = ((alen-1) >> 5) + 1;
  block_min = (int *) malloc (sizeof(int) * block_cnt);
  for(i = j = 0; i < alen; i++){
    if(i % 32 == 0){
      if(i > 0) j++;
      block_min[j] = i;
    } else if(VAL_LT(array[i],array[block_min[j]])){
      block_min[j] = i;
    }
  }
  /* make a sparse table for the rmq of the blocks.
   * sparse[j][i] represents the minimum in
   * block[i] to block[i + 2^{j+1} - 1] */
  rows = intlog2(block_cnt);
  sparse = NULL;
  /* sparse tables aren't needed when the array is less than 32 elements long */
  if(rows > 0){
    sparse = (int **) malloc (sizeof(int *) * rows);
    /* first row is min of adjacent entries. Table entries are
     * converted to positions in original array */
    sparse[0] = (int *) malloc (sizeof(int) * (block_cnt - 1));
    for(i = 0; i < block_cnt - 1; i++){
      if(VAL_LT(array[block_min[i+1]],array[block_min[i]]))
        sparse[0][i] = block_min[i+1];
      else
        sparse[0][i] = block_min[i];
    }
    for(j = 1; j < rows; j++){
      rowelmlen = 2 << j;    /* 2^{j+1} */
      cols = block_cnt - rowelmlen + 1;
      sparse[j] = (int *) malloc (sizeof(int) * cols);
      for(i = 0; i < cols; i++){
        if(VAL_LT(array[sparse[j-1][i + (rowelmlen >> 1)]],array[sparse[j-1][i]]))
          sparse[j][i] = sparse[j-1][i + (rowelmlen >> 1)];
	else
	  sparse[j][i] = sparse[j-1][i];	
      }
    }
  }
  
  /* create integers for constant time rmq inside the blocks
   * In each block:
   * - g[i]: the first position to the left of i
   * where array[g[i]] < array[i] (or -1 if there is no such position).
   * - l[i]: the jth bit of l[i] is 1 iff j is the first
   * position left of i where array[j] < array[i] */
  labels = (int *) malloc(sizeof(int) * alen);
  for(i = 0; i < alen; i++){
    if(i % 32 == 0) gstacksize = 0;
    labels[i] = 0;
    while(gstacksize > 0 && (VAL_LT(array[i],array[gstack[gstacksize-1]]))){
      gstacksize--;
    }
    if(gstacksize > 0){
      g = gstack[gstacksize-1];
      labels[i] = labels[g] | (1 << (g%32));
    }
    gstack[gstacksize++] = i;
  }
  info->array = array;
  info->sparse = sparse;
  info->block_min = block_min;
  info->labels = labels;
  info->alen = alen;
  return info;  
}


/*
 * Return the position in array which gives the minimum value
 * in the subarray rmqinfo.array[x..y] using preprocessed information.
 * When there are multiple positions with the same minimum value,
 * in the range, the smallest index is returned.
 */
int rm_query(const struct rmqinfo * info, int l, int r){
  int blocknum_l, blocknum_r, blockdiff, blockmin;
  int tmp, v, bpos;
  int v1, v2, pos1, pos2;
  if(l == r) return l;
  if(l > r){
    tmp = l; l = r; r = tmp;
  }
  blocknum_l = (l >> 5); blocknum_r = (r >> 5);  /* obtain which blocks l and r will come in */
  bpos = blocknum_l << 5;
  switch(blockdiff = blocknum_r - blocknum_l){
  case 0: /* one inblock query in block blocknum_l. from position (l%32) to (r%32) */
    v = clearbits(info->labels[r], l % 32); /* clear (x - 1) insiginificant bits */
    return ((v == 0) ? r : bpos + lsbset(v));
    break;
  case 1:  /* two inblock queries. in block blocknum_l and blocknum_r.
	    * in blocknum_l: postion (l%32) to 31  
	    * in blocknum_r: postion 0 to (r%32) */
    tmp = bpos + 31;
    v1 = clearbits(info->labels[tmp], l%32);
    v2 = info->labels[r];
    pos1 = (v1 == 0) ? tmp : (bpos + lsbset(v1));
    pos2 = (v2 == 0) ? r : lsbset(v2) + (blocknum_r<<5);
    return((VAL_LT(info->array[pos2],info->array[pos1])) ? pos2 : pos1);
    break;
  default: /* two inblock queries, and a query over the blocks.
	    * in blocknum_l: postion (l%32) to 31
	    * in blocknum_r: postion 0 to (r%32).
	    * block (blocknum_l+1) to (blonum_r-1) */
    tmp = bpos + 31;
    v1 = clearbits(info->labels[tmp], l%32);
    v2 = info->labels[r];
    pos1 = (v1 == 0) ? tmp : (bpos + lsbset(v1));
    pos2 = (v2 == 0) ? r : lsbset(v2) + (blocknum_r<<5);
    if(blockdiff == 2){ /* (blocknum_l+1) == (blonum_r-1) */
      blockmin = info->block_min[blocknum_l+1];
    } else {
      /* rmq of blocknum_l+1 to blocknum_r-1 */
      int t1, t2, k;
      k = intlog2(blockdiff-1) - 1;
      t1 = info->sparse[k][blocknum_l+1];
      t2 = info->sparse[k][blocknum_r - (1 << (k+1))];
      blockmin = (VAL_LT(info->array[t2],info->array[t1])) ? t2 : t1;
    }
    pos1 = (VAL_LT(info->array[blockmin],info->array[pos1])) ? blockmin : pos1;
    return((VAL_LT(info->array[pos2],info->array[pos1])) ? pos2 : pos1);
  }
}

void rm_free(struct rmqinfo * info){
  int block_cnt, rows, i;
  block_cnt = ((info->alen-1) >> 5) + 1;
  rows = intlog2(block_cnt);
  for(i = 0; i < rows; i++)
    free(info->sparse[i]);
  free(info->sparse);
  free(info->block_min);
  free(info->labels);
  free(info);
}

int main() {
  long long a[] = {34, 234, 134, 41, 55};
  struct rmqinfo* rmq;
  rmq = rm_query_preprocess(a, 5);
  printf("%d\n", rm_query(rmq, 3, 4));
  return 0;
}