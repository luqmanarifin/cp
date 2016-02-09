#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

long long fact[N], ifact[N];
int n, m, u[10], v[10];

// permut - is reversed - panjang len
int p[10], r[10], len;
int cnt[20], ada[N];

long long power(long long a, long long b) {
  if(b == 0) return 1;
  long long temp = power(a, b / 2);
  temp = temp * temp % mod;
  if(b & 1) {
    temp = temp * a % mod;
  }
  return temp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long c(int n, int k) {
  return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

long long stars(int n, int k) {
  return c(n + k - 1, n);
}

long long find() {
  for(int i = 0; i < len; i++) {
    ada[u[p[i]]] = 0;
    ada[v[p[i]]] = 0;
  }
  
  int cs = 0, last = -1;
  for(int i = 0; i < len; i++) {
    if(r[i]) {  // v[i] -> u[i]
      if(last == v[p[i]]) {
        ada[u[p[i]]]++;
        cnt[cs - 1]++;
      } else {
        ada[v[p[i]]]++;
        ada[u[p[i]]]++;
        cnt[cs++] = 2;
      }
      last = u[p[i]];
    } else {    // u[i] -> v[i]
      if(last == u[p[i]]) {
        ada[v[p[i]]]++;
        cnt[cs - 1]++;
      } else {
        ada[u[p[i]]]++;
        ada[v[p[i]]]++;
        cnt[cs++] = 2;
      }
      last = v[p[i]];
    }
  }
  for(int i = 0; i < len; i++) {
    if(ada[u[p[i]]] > 1) return 0;
    if(ada[v[p[i]]] > 1) return 0;
  }
  int tot = 0;
  for(int i = 0; i < cs; i++) tot += cnt[i];
  return stars(n - tot, cs + 1) * fact[n - tot] % mod;
}

int main() {
  fact[0] = ifact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
      scanf("%d %d", u + i, v + i);
      u[i]--; v[i]--;
    }
    long long ans = fact[n];
    for(int mask = 1; mask < (1 << m); mask++) {
      len = __builtin_popcount(mask);
      int pt = 0;
      for(int i = 0; i < m; i++) {
        if(mask & (1 << i)) {
          p[pt++] = i;
        }
      }
      do {
        for(int flip = 0; flip < (1 << len); flip++) {
          for(int i = 0; i < len; i++) {
            r[i] = (flip & (1 << i));
          }
          long long add = find();
          if(len % 2) {
            ans -= add;
          } else {
            ans += add;
          }
        }
      } while(next_permutation(p, p + len));
    }
    ans %= mod;
    if(ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}
