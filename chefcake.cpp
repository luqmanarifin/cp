#include <bits/stdc++.h>
 
using namespace std;
 
const long long pol = 1e7 + 5;
const long long mod = 1e9 + 7;
 
long long num[pol];
int sp[pol][24];
 
#define sq(a, mod) (a * a % mod)
 
int query(int l, int r) {
  int at = (__builtin_clz(r - l + 1) ^ 31);
  if(num[sp[l][at]] < num[sp[r - (1 << at) + 1][at]]) {
    return sp[l][at];
  } else {
    return sp[r - (1 << at) + 1][at];
  }
}
 
int main() {
  long long n, k, q;
  long long a, b, c, d, e, f, r, s, t, m, seed;
  long long l1, la, lc, lm, d1, da, dc, dm;
  scanf("%lld %lld %lld", &n, &k, &q);
  scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",
    &a, &b, &c, &d, &e, &f, &r, &s, &t, &m, &num[0]);
  scanf("%lld %lld %lld %lld %lld %lld %lld %lld",
    &l1, &la, &lc, &lm, &d1, &da, &dc, &dm);
  
  long long cok = t % s;
  for(int x = 2; x <= n; x++) {
    cok = cok * t % s;
    if(cok <= r) {
      num[x - 1] = (a * sq(num[x - 2], m) + b * num[x - 2] + c) % m;
    } else {
      num[x - 1] = (d * sq(num[x - 2], m) + e * num[x - 2] + f) % m;
    }
  }
  
  for(int i = 0; i < n; i++) {
    sp[i][0] = i;
  }
  for(int j = 1; j < 24; j++) {
    if((1 << j) > 2 * k) {
      break;
    }
    int last = (1 << j) - 1;
    for(int i = 0; i + last < n; i++) {
      sp[i][j] = sp[i + (1 << (j - 1))][j - 1];
      if(num[sp[i][j - 1]] < num[sp[i][j]]) {
        sp[i][j] = sp[i][j - 1];
      }
    }
  }
  
  long long sum = 0, product = 1;
  while(q--) {
    l1 = (la * l1 + lc) % lm;
    d1 = (da * d1 + dc) % dm;
    int l = l1 + 1;
    int r = min(l + k - 1 + d1, n);
    l--; r--;
    // rmq code here
    long long mini = num[query(l, r)];
    
    sum += mini;
    product *= mini;
    product %= mod;
  }
  
  printf("%lld %lld\n", sum, product);
  return 0;
}