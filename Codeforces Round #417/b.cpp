#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int inf = 1e9;

char s[N][N];
int dp[N][3];

int main() {
  for (int i = 0; i < N; i++) dp[i][0] = dp[i][1] = dp[i][2] = inf;
  
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  dp[n][0] = -1;
  for (int i = n - 1; i >= 0; i--) {
    int f = -1, l = -1;
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '1') {
        if (f == -1) f = j;
        l = j;
      }
    }
    if (f == -1) {
      dp[i][0] = dp[i+1][0] + 1;
      dp[i][1] = dp[i+1][1] + 1;
      dp[i][2] = min(dp[i][0], dp[i][2]);
    } else {
      dp[i][0] = min(dp[i+1][1] + m + 2, dp[i+1][0] + 1 + 2 * l);
      dp[i][1] = min(dp[i+1][0] + m + 2, dp[i+1][1] + 1 + 2 * (m + 1 - f));
      dp[i][2] = min(dp[i+1][0] + l + 1, dp[i+1][1] + 1 + (m + 1 - f));
    }
  }
  for (int i = 0; i < n; i++) {
    bool ada = 0;
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '1') {
        ada = 1;
      }
    }
    if (ada) {
      cout << dp[i][2] << endl;
      return 0;
    }
  }
  cout << 0 << endl;

  return 0;
}
