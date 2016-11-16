#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const double inf = 1e18;

double dd[N], dist[N][N];
int h[N], w[N], d[N], k[N];
int from[N];

int main() {
  freopen("street.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    fill(dd, dd + N, inf);
    
    int n, L, U;
    scanf("%d %d %d", &n, &L, &U);
    for (int i = 1; i <= n; i++) scanf("%d %d %d %d", h + i, w + i, d + i, k + i);
    dist[0][n + 1] = dist[n + 1][0] = L;
    for (int i = 1; i <= n; i++) {
      dist[0][i] = dist[i][0] = d[i];
      dist[n + 1][i] = dist[i][n + 1] = L - (d[i] + h[i]);
      assert(d[i] + h[i] <= L);
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        int dx = min(abs(d[i] + h[i] - d[j]), abs(d[j] + h[j] - d[i]));
        int dy = max(0, U - w[i] - w[j]);
        if (k[i] == k[j]) {
          dist[i][j] = dx;
        } else {
          //printf("%d %d: %d>%d %d>%d\n", i, j, d[i], d[j] + h[j], d[j], d[i] + h[i]);
          if (d[i] > d[j] + h[j] || d[j] > d[i] + h[i]) {
            dist[i][j] = sqrt(1LL * dx * dx + 1LL * dy * dy);
          } else {
            dist[i][j] = dy;
          }
        }
      }
    }
    /*
    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= n + 1; j++) {
        printf("%d %d %.5f\n", i, j, dist[i][j]);
      }      
    }
    */
    
    priority_queue<pair<double, int>> pq;
    dd[0] = 0;
    pq.emplace(dd[0], 0);
    while (!pq.empty()) {
      double cost; int now;
      tie(cost, now) = pq.top();
      cost = -cost;
      pq.pop();
      //printf("%d\n", now);
      if (abs(cost - dd[now]) > 1e-9) continue;
      //printf("%d\n", now);
      for (int i = 0; i <= n + 1; i++) {
        double ncos = cost + dist[now][i];
        if (ncos < dd[i]) {
          dd[i] = ncos;
          pq.emplace(-dd[i], i);
          from[i] = now;
        }
      }
    }
    //for (int i = 0; i <= n + 1; i++) printf("%d %.6f from %d\n", i, dd[i], from[i]);
    printf("%.6f\n", dd[n + 1]);
  }
  return 0;
}
