#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

const int N = 505;

int dp[N][N][N], ans[N][N];

void add(int& at, long long val) {
  at += val % mod;
  if (at >= mod) at -= mod;
}

int main() {
  dp[1][0][0] = 1;
  dp[2][1][0] = 2;
  dp[3][2][0] = 4;
  dp[3][1][1] = 2;
  for (int i = 3; i + 1 < N; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= i; k++) {
        // pinggir
        add(dp[i+1][j+1][k], 2LL * dp[i][j][k]);
        // tengah tapi ga jeglong
        add(dp[i+1][j][k+1], 1LL*(i-1 - 2*k) * dp[i][j][k]);
        // jeglong
        add(dp[i+1][j+1][k], 2LL*k * dp[i][j][k]);
      }
    }
  }
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      for (int k = 0; k < N; k++) {
        add(ans[i][j], dp[i][j][k]);
      }
    }
    for (int j = i; j >= 0; j--) {
      add(ans[i][j], ans[i][j+1]);
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", ans[n][k]);
  }
  return 0;
}
