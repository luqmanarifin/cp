#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int inf = 1e9;

int a[5005][2];

int d[N][N];
int dp[5005][3][2];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, m, K;
    scanf("%d %d %d", &n, &m, &K);
    for (int i = 0; i < N; i++) for (int j = 0; j < 3; j++) dp[i][j][0] = dp[i][j][1] = inf;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) d[i][j] = inf;
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      d[u][v] = min(d[u][v], w);
      d[v][u] = min(d[v][u], w);
    }
    a[0][0] = a[0][1] = 1;
    for (int i = 1; i <= K; i++) scanf("%d %d", &a[i][0], &a[i][1]);
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
    //for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) printf("%d %d %d\n", i, j, d[i][j]);
    for (int i = 0; i < 5005; i++) {
      for (int j = 0; j < 3; j++) {
        dp[i][j][0] = dp[i][j][1] = inf;
      }
    }
    dp[0][0][0] = dp[0][0][1] = 0;
    for (int i = 1; i <= K; i++) {
      for (int j = min(i, 2); j >= 0; j--) {
        if (j) dp[i][j][0] = min(dp[i][j][0], dp[i-1][j-1][0] + d[a[i][0]][a[i-1][0]]);
        if (j && i-j>=0) dp[i][j][0] = min(dp[i][j][0], dp[i-1][j-1][1] + d[a[i][0]][a[i-j][1]]);
        
        if (j+1<=2) dp[i][j][1] = min(dp[i][j][1], dp[i][j+1][0] + d[a[i-j][1]][a[i][0]]);
        if (j+1<=2 && i-j-1>=0) dp[i][j][1] = min(dp[i][j][1], dp[i][j+1][1] + d[a[i-j][1]][a[i-j-1][1]]);
        
        //printf("%d %d %d: %d\n", i, i-j, 0, dp[i][j][0]);
        //printf("%d %d %d: %d\n", i, i-j, 1, dp[i][j][1]);
      }
    }
    int ans = dp[K][0][1];
    if (ans >= inf) ans = -1;
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}
