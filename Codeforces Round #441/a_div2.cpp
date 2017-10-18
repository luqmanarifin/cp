#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int dp[N][3];
int a[N][N];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%d %d %d", &a[0][1], &a[0][2], &a[1][2]);
  a[1][0] = a[0][1];
  a[2][0] = a[0][2];
  a[2][1] = a[1][2];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      dp[i][j] = 1e9;
    }
  }
  dp[1][0] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j == k) continue;
        dp[i][j] = min(dp[i][j], dp[i-1][k] + a[j][k]);
      }
    }
  }
  int ans = 1e9;
  for (int j = 0; j < 3; j++) ans = min(ans, dp[n][j]);
  cout << ans << endl;
  return 0;
}
