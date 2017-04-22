#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const long long inf = 1e18;
const double eps = -1e8;

int e[N], s[N], d[N][N];
long long dist[N][N];

double dp[N][N];

bool equal(double a, double b) {
  return abs(a - b) < eps;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d %d", e + i, s + i);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = dp[i][j] = inf;
        dist[i][i] = 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &d[i][j]);
        if (d[i][j] != -1) {
          dist[i][j] = d[i][j];
        }
      }
    }
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    /*
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        printf("jarak %d %d: %lld\n", i, j, dist[i][j]);
      }
    }
    */
    for (int st = 1; st <= n; st++) {
      dp[st][st] = 0;
      priority_queue<pair<double, int>> pq;
      pq.emplace(0, st);
      while (!pq.empty()) {
        double cost;
        int now;
        tie(cost, now) = pq.top();
        cost = -cost;
        pq.pop();
        //printf("%.15f %.15f\n", cost, dp[st][now]);
        if (cost > dp[st][now]) continue;
        //printf("%d\n", now);
        for (int i = 1; i <= n; i++) {
          if (dist[now][i] <= e[now]) {
            double ncos = cost + (double) dist[now][i] / s[now];
            if (ncos < dp[st][i]) {
              dp[st][i] = ncos;
              pq.emplace(-dp[st][i], i);
            }
          }
        }
      }
    }
    printf("Case #%d:", tt);
    while (q--) {
      int u, v;
      scanf("%d %d", &u, &v);
      printf(" %.15f", dp[u][v]);
    }
    printf("\n");
  }

  return 0;
}
