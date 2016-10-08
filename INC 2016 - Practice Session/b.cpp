#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int inf = 1e9;

int dist[N];
vector<pair<int, int>> edge[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < N; i++) edge[i].clear();

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].emplace_back(v, 0);
      edge[v].emplace_back(u, 1);
    }
    printf("Case #%d:\n", tt);

    int q;
    scanf("%d", &q);
    while(q--) {
      int u, v;
      scanf("%d %d", &u, &v);
      priority_queue<pair<int, int>> pq;
      fill(dist, dist + N, inf);
      dist[u] = 0;
      pq.emplace(0, u);
      while (!pq.empty()) {
        int cost, now;
        tie(cost, now) = pq.top();
        pq.pop();
        cost = -cost;
        if (cost != dist[now]) continue;
        for (auto it : edge[now]) {
          int near = it.first;
          int ncos = cost + it.second;
          if (ncos < dist[near]) {
            dist[near] = ncos;
            pq.emplace(-dist[near], near);
          }
        }
      }
      if (dist[v] == inf) dist[v] = -1;
      printf("%d\n", dist[v]);
    }
  }

  return 0;
}
