#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const long long inf = 1e18;

int e[N], s[N], d[N][N];
long long dist[N];
double dp[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    fill(dp, dp + N, inf);
    
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d %d", e + i, s + i);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &d[i][j]);
      }
    }
    for (int i = 1; i <= n; i++) {
      dist[i] = dist[i-1] + d[i-1][i];
    }
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (dist[j] - dist[i] <= e[i]) {
          dp[j] = min(dp[j], dp[i] + (double) (dist[j] - dist[i]) / s[i]);
        }
      }
    }
    printf("Case #%d:", tt);
    while (q--) {
      int u, v;
      scanf("%d %d", &u, &v);
      printf(" %.15f\n", dp[n]);
    }
  }

  return 0;
}
