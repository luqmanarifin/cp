#include <stdio.h>

#define pol (long long) 1e7 + 5
#define mod (long long) 1e9 + 7
#define sq(a, mod) (a * a % mod)

int VAL_LT(long long a, long long b) {
  return a <= b;
}

struct rmqinfo {
  int alen;
  long long * array;
  int ** sparse;
  int * block_min;
  int * labels;
};

struct rmqinfo * rmq;

static inline int clearbits(int n, int x){
  return((n >> x) << x);  
}

static inline int intlog2(int n){
#ifdef __GNUC__
  return(__builtin_clz(n)^31);
#else
  int res;
  for(res = 0; n > 0; n >>= 1, res++);
  return(res-1);
#endif
}

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

struct rmqinfo * rm_query_preprocess(long long * array, int alen){
  struct rmqinfo * info;
  int i, j, g, rows, cols, block_cnt, rowelmlen;
  int * block_min, **sparse, *labels;
  int gstack[32], gstacksize = 0;
  
  info = (struct rmqinfo *) malloc(sizeof(struct rmqinfo));
  
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

  rows = intlog2(block_cnt);
  sparse = NULL;

  if(rows > 0){
    sparse = (int **) malloc (sizeof(int *) * rows);
    sparse[0] = (int *) malloc (sizeof(int) * (block_cnt - 1));
    for(i = 0; i < block_cnt - 1; i++){
      if(VAL_LT(array[block_min[i+1]],array[block_min[i]]))
        sparse[0][i] = block_min[i+1];
      else
        sparse[0][i] = block_min[i];
    }
    for(j = 1; j < rows; j++){
      rowelmlen = 2 << j;
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

int rm_query(int l, int r){
  int blocknum_l, blocknum_r, blockdiff, blockmin;
  int tmp, v, bpos;
  int v1, v2, pos1, pos2;
  if(l == r) return l;
  if(l > r){
    tmp = l; l = r; r = tmp;
  }
  blocknum_l = (l >> 5); blocknum_r = (r >> 5); 
  bpos = blocknum_l << 5;
  switch(blockdiff = blocknum_r - blocknum_l){
  case 0: 
    v = clearbits(rmq->labels[r], l % 32);
    return ((v == 0) ? r : bpos + lsbset(v));
    break;
  case 1: 
    tmp = bpos + 31;
    v1 = clearbits(rmq->labels[tmp], l%32);
    v2 = rmq->labels[r];
    pos1 = (v1 == 0) ? tmp : (bpos + lsbset(v1));
    pos2 = (v2 == 0) ? r : lsbset(v2) + (blocknum_r<<5);
    return((VAL_LT(rmq->array[pos2],rmq->array[pos1])) ? pos2 : pos1);
    break;
  default:
  
    tmp = bpos + 31;
    v1 = clearbits(rmq->labels[tmp], l%32);
    v2 = rmq->labels[r];
    pos1 = (v1 == 0) ? tmp : (bpos + lsbset(v1));
    pos2 = (v2 == 0) ? r : lsbset(v2) + (blocknum_r<<5);
    if(blockdiff == 2){ 
      blockmin = rmq->block_min[blocknum_l+1];
    } else {
      int t1, t2, k;
      k = intlog2(blockdiff-1) - 1;
      t1 = rmq->sparse[k][blocknum_l+1];
      t2 = rmq->sparse[k][blocknum_r - (1 << (k+1))];
      blockmin = (VAL_LT(rmq->array[t2],rmq->array[t1])) ? t2 : t1;
    }
    pos1 = (VAL_LT(rmq->array[blockmin],rmq->array[pos1])) ? blockmin : pos1;
    return((VAL_LT(rmq->array[pos2],rmq->array[pos1])) ? pos2 : pos1);
  }
}

long long num[pol];

int main() {
  long long n, k, q;
  long long a, b, c, d, e, f, r, s, t, m;
  long long l1, la, lc, lm, d1, da, dc, dm;
  scanf("%lld %lld %lld", &n, &k, &q);
  scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",
    &a, &b, &c, &d, &e, &f, &r, &s, &t, &m, &num[0]);
  scanf("%lld %lld %lld %lld %lld %lld %lld %lld",
    &l1, &la, &lc, &lm, &d1, &da, &dc, &dm);
  
  long long cok = t % s;
  int x;
  for(x = 2; x <= n; x++) {
    cok = cok * t;
    if(cok >= s) {
      cok %= s;
    }
    if(cok <= r) {
      num[x - 1] = (a * sq(num[x - 2], m) + b * num[x - 2] + c);
    } else {
      num[x - 1] = (d * sq(num[x - 2], m) + e * num[x - 2] + f);
    }
    if(num[x - 1 >= m]) {
      num[x - 1] %= m;
    }
  }
  rmq = rm_query_preprocess(num, n);
  
  long long sum = 0, product = 1;
  while(q--) {
    l1 = (la * l1 + lc) % lm;
    d1 = (da * d1 + dc) % dm;
    int l = l1 + 1;
    int r = (l + k - 1 + d1 < n? l + k - 1 + d1 : n);
    l--; r--;
    // rmq code here
    long long mini = num[rm_query(l, r)];
    
    sum += mini;
    product *= mini;
    product %= mod;
  }
  
  printf("%lld %lld\n", sum, product);
  
  return 0;
}
