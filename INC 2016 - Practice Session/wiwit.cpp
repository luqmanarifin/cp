#include <bits/stdc++.h>

using namespace std;

const int N = 15, inf = 1e8;

int dp[1<<N];
int vis[1<<N];
int a[N][N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n;
    scanf("%d", &n);
    n *= 3;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        scanf("%d", a[i]+j);
    int m = 1<<n;
    fill(dp, dp + m, 0);
    fill(vis, vis + m, 0);
    vis[0] = 1;
    dp[0] = inf;
    for (int mask = 0; mask < m; mask++) {
      if (vis[mask] == 0) continue;
      //printf("mask %d\n", mask);
      int p = -1;
      for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
          p = i;
          break;
        }
      }
      if (p == -1) continue;
      for (int i = p + 1; i < n; i++) {
        if (mask & (1 << i)) continue;
        for (int j = i + 1; j < n; j++) {
          if (mask & (1 << j)) continue;
          int to = (mask | (1 << p) | (1 << i) | (1 << j));
          int cur = min(dp[mask], a[p][i] + a[i][j] + a[p][j]);
          dp[to] = max(dp[to], cur);
          vis[to] = 1;
        }
      }
    }
    assert(vis[m-1]);
    printf("Case #%d: %d\n", tc, dp[m-1]);
  }

  return 0;
}
