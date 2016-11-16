#include <bits/stdc++.h>

using namespace std;

int dp[50][50];

const int mod = 1e9 + 7;
const int N = 1e6 + 5;

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

long long c(int n, int k) {
  if (n < k || n < 0 || k < 0) return 0;
  long long tmp = fact[n] * ifact[k] % mod;
  tmp = tmp * ifact[n - k] % mod;
  return tmp;
}

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  
  
  for (int k = 1; k <= 10; k++) {
    for (int n = k; n <= 10; n++) {
      memset(dp, 0, sizeof(dp));
      dp[0][0] = 1;
      for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
          for (int take = 1; j - take >= 0; take++) {
            dp[i][j] += dp[i - 1][j - take] * c(n - j + take, take);
            dp[i][j] %= mod;
          }
        }
      }
      printf("%d %d %d\n", n, k, (int) dp[k][n] / fact[k]);
      long long ans = (k == 1? 1 : c(n, k) * fact[k] % mod);
      //assert(ans == dp[k][n]);
    }
  }

  return 0;
}
