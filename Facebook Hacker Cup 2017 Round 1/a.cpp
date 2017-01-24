#include <bits/stdc++.h>

using namespace std;

const int N = 305;
const long long inf = 1e18;

long long dp[N][N], got[N][N];
int a[N][N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) got[i][j] = inf;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
      }
      sort(a[i] + 1, a[i] + 1 + m);
      got[i][0] = 0;
      for (int j = 1; j <= m; j++) {
        got[i][j] = got[i][j - 1] + a[i][j];
      }
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dp[i][j] = inf;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        for (int k = max(0, i - 1); k <= j; k++) {
          dp[i][j] = min(dp[i][j], dp[i-1][k] + got[i][j-k] + 1LL*(j-k)*(j-k));
        }
      }
    }
    printf("Case #%d: %I64d\n", tt, dp[n][n]);
    cerr << tt << " done!" << endl;
  }
  return 0;
}
