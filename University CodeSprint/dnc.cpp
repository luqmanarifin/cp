#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
int mod;

long long fact[N], ifact[N];
long long ways[N], dp[N][N], got[N][N];   // got x sebanyak k kali
long long lol[N][N];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long c(int n, int k) {
  if (n < k || n < 0 || k < 0) return 0;
  long long tmp = fact[n] * ifact[k] % mod;
  tmp = tmp * ifact[n - k] % mod;
  return tmp;
}

int main() {
  int n;
  scanf("%d %d", &n, &mod);
  
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      lol[i][j] = fact[i] * ifact[j] % mod;
    }
  }
  
  for (int i = 0; i < N; i++) dp[0][i] = 1;
  for (int i = 1; i <= n; i++) {
    int q = i-1;
    for (int j = 1; j < N; j++) {
      long long &cur = dp[q][j];
      if (j > q) {
        cur = dp[q][j-1];
        continue;
      }
      for (int k = 0; j * k <= q; k++) {
        long long add = dp[q-k*j][j-1] * got[j][k] % mod * lol[q][q-k*j] % mod;
        cur += add;
        if (cur >= mod) cur -= mod;
      }
    }
    ways[i] = dp[q][q/2] * i % mod;
    got[i][0] = 1;
    for (int j = 1; i * j <= n; j++) {
      got[i][j] = ifact[j] * power(ifact[i], j) % mod;
      got[i][j] = got[i][j] * power(ways[i] * i % mod, j) % mod;
    }
  }
  printf("%lld\n", ways[n]);
  return 0;
}