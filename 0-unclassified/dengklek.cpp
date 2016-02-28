#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9 + 1e8;
const int N = 2e5 + 5;

int a[2005][205];
int dist[2005][205];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int q;
  int bx = 1, by = 1;
  scanf("%d", &q);
  int ans = a[1][1];
  while(q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        dist[i][j] = inf;
      }
    }
    priority_queue<tuple<int, int, int>> pq;
    dist[bx][by] = 0;
    pq.emplace(0, bx, by);
    while(!pq.empty()) {
      int c, u, v;
      tie(c, u, v) = pq.top();
      c = -c;
      pq.pop();
      if(dist[u][v] != c) continue;
      if(v + 1 <= m) {
        if(dist[u][v + 1] > c + a[u][v + 1]) {
          dist[u][v + 1] = c + a[u][v + 1];
          pq.emplace(-dist[u][v + 1], u, v + 1);
        }
      }
      if(v - 1 >= 1) {
        if(dist[u][v - 1] > c + a[u][v - 1]) {
          dist[u][v - 1] = c + a[u][v - 1];
          pq.emplace(-dist[u][v - 1], u, v - 1);
        }
      }
      if(v == 1 || v == m) {
        if(u + 1 <= n) {
          if(dist[u + 1][v] > c + a[u + 1][v]) {
            dist[u + 1][v] = c + a[u + 1][v];
            pq.emplace(-dist[u + 1][v], u + 1, v);
          }
        }
        if(u - 1 >= 1) {
          if(dist[u - 1][v] > c + a[u - 1][v]) {
            dist[u - 1][v] = c + a[u - 1][v];
            pq.emplace(-dist[u - 1][v], u - 1, v);
          }
        }
      }
    }
    printf("nambah %d\n", dist[x][y]);
    ans += dist[x][y];
    bx = x; by = y;
  }
  cout << ans << endl;
  return 0;
}
