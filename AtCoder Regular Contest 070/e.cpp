#include <bits/stdc++.h>

using namespace std;

const int N = 405;
const int inf = 2e9;

int dp[N][N];
int l[N], len[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", l + i, len + i);
    len[i] -= l[i];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = inf;
    }
  }
  for (int i = 0; i < N; i++) {
    dp[0][i] = abs(i - l[0]);
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = max(0, j-len[i-1]); k <= min(N - 1, j+len[i]); k++) {
        dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(j - l[i]));
      }
    }
  }
  int ans = inf;
  for (int i = 0; i < N; i++) ans = min(ans, dp[n - 1][i]);
  cout << ans << endl;
  return 0;
}
