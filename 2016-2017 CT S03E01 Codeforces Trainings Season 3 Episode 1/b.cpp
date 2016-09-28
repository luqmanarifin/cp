#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const int N = 5e4 + 5;

long long dp[N][105];
int k[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) for (int j = 0; j < 105; j++) dp[i][j] = inf;
    
    int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for (int i = 0; i < n; i++) scanf("%d", k + i);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= m; j++) {
        if (j + k[i] <= m) {
          dp[i + 1][j + k[i]] = min(dp[i + 1][j + k[i]], dp[i][j]);
        } else {
          dp[i + 1][m] = min(dp[i + 1][m], dp[i][j] + a * (j + k[i] - m));
        }
      }
      for (int j = 0; j < m; j++) {
        dp[i + 1][0] = min(dp[i + 1][0], dp[i + 1][m - j] + b * j);
      }
      //for (int j = 0; j < m; j++) if (dp[i+1][j] && dp[i+1][j] != inf) printf("%d %d %I64d\n", i+1, j, dp[i+1][j]);
    }
    printf("%I64d\n", dp[n][0]);
  }

  return 0;
}
