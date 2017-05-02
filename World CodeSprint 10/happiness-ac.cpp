#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

const int N = 3005;

int dp[N][N], ans[N][N];

void add(int& at, long long val) {
  at += val % mod;
  if (at >= mod) at -= mod;
}

int main() {
  dp[1][0] = 1;
  dp[2][1] = 2;
  dp[3][0] = 4;
  dp[3][1] = 2;
  for (int i = 3; i + 1 < N; i++) {
    for (int j = 0; j <= i; j++) {
      // pinggir
      add(dp[i+1][j], 2LL * dp[i][j]);
      // tengah tapi ga jeglong
      add(dp[i+1][j+1], 1LL*(i-1 - 2*j) * dp[i][j]);
      // jeglong
      add(dp[i+1][j], 2LL*j * dp[i][j]);
      //printf("%d %d: %d\n", i, j, dp[i][j]);
    }
  }
  for (int i = 3; i < N; i++) {
    for (int j = 1; j <= i; j++) {
      add(dp[i][j], dp[i][j-1]);
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (n == k) {
      puts("0");
    } else if (n < 3) {
      printf("%d\n", dp[n][k]);
    } else {
      printf("%d\n", dp[n][n-k-1]);
    }
  }
  return 0;
}
