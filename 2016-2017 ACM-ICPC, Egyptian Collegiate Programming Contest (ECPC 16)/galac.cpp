#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int mod = 1e9 + 7;

long long fact[N], ifact[N];

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

long long dp[N][N];

int main() {
  freopen("galactic.in", "r", stdin);
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  dp[0][0] = 1;
  for (int i = 1; i <= 1000; i++) {
    for (int j = i; j <= 1000; j++) {
      dp[i][j] = (dp[i][j - 1] * i + dp[i - 1][j - 1]) % mod;
      //printf("%d %d %I64d\n", i, j, dp[i][j]);
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] *= fact[i];
      dp[i][j] %= mod;
    }
  }
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (n < k) {
      puts("0");
      continue;
    }
    printf("%d\n", dp[k][n]);
  }

  return 0;
}
