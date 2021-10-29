#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
const int N = 505;

long long power[N][N], c[N][N];
long long dp[N][N];

int main() {
  for (int i = 1; i < N; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
    }
    power[i][0] = 1;
    for (int j = 1; j < N; j++) {
      power[i][j] = power[i][j-1] * i % mod;
    }
  }

  int n, x;
  scanf("%d %d", &n, &x);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      dp[i][j] = power[min(i-1, j)][i];
      if (j >= i) {
        for (int alive = 1; alive <= i; alive++) {
          dp[i][j] += c[i][alive] * dp[alive][j-i+1] % mod * power[i-1][i-alive] % mod;
          dp[i][j] %= mod;
        }
      }
    }
  }
  cout << dp[n][x] << endl;
  return 0;
}
