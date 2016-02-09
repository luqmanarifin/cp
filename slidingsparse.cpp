#include <bits/stdc++.h>
 
using namespace std;
 
const long long pol = 1e7 + 5;
const long long mod = 1e9 + 7;
 
long long num[pol];
long long mini[pol];
long long n, k, q;

#define sq(a, mod) (a * a % mod)
 
int query(int l, int r) {
  return min(mini[l], mini[r - k + 1]);
}
 
int main() {
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
  
  multiset<long long> mul;
  for(int i = 0; i < k; i++) {
    mul.insert(num[i]);
  }
  mini[0] = *mul.begin();
  for(int i = 1; i + k <= n; i++) {
    mul.erase(mul.find(num[i - 1]));
    mul.insert(num[i + k - 1]);
    mini[i] = *mul.begin();
  }
  
  long long sum = 0, product = 1;
  while(q--) {
    l1 = (la * l1 + lc) % lm;
    d1 = (da * d1 + dc) % dm;
    int l = l1 + 1;
    int r = min(l + k - 1 + d1, n);
    l--; r--;
    // rmq code here
    long long mini = query(l, r);
    
    sum += mini;
    product *= mini;
    product %= mod;
  }
  
  printf("%lld %lld\n", sum, product);
  return 0;
}