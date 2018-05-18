#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 155;
const int inf = 1e18;

int back[N][N], dist[N][N], cost[N][N];
int n, m, q;
vector<pair<int, int>> edge[N];

void bellman(int source, int pre[], int d[], int prec[]) {
  for (int i = 0; i < n; i++) {
    d[i] = inf;
    pre[i] = -1;
    prec[i] = inf;
  }
  d[source] = 0;
  for (int it = 1; it < n; it++) {
    for (int i = 0; i < n; i++) {
      for (auto it : edge[i]) {
        int j = it.first;
        int c = it.second;
        if (d[i] + c < d[j]) {
          d[j] = d[i] + c;
          pre[j] = i;
          prec[j] = c;
        }
      }
    }
  }  
}

bool vis[N];

bool dfs(int from, int to) {
  if (to < 0) return 0;
  if (vis[to]) return 0;
  vis[to] = 1;
  int bef = back[from][to];
  if (bef != -1 && dist[from][bef] + cost[from][to] < dist[from][to]) {
    return 1;
  }
  return dfs(from, back[from][to]);
}

bool siklik(int from, int to) {
  memset(vis, 0, sizeof(vis));
  bool ada = dfs(from, to);
  if (!vis[from]) return 1;
  return ada;
}

main() {
  while (scanf("%lld %lld %lld", &n, &m, &q) && n && q) {
    for (int i = 0; i < N; i++) edge[i].clear();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = inf;
      }
    }
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%lld %lld %lld", &u, &v, &w);
      dist[u][v] = min(dist[u][v], w);
    }
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (dist[i][k] >= inf || dist[k][j] >= inf) continue;
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
          if (dist[j][j] < 0 && dist[k][j] < inf && dist[j][i] < inf) {
            dist[k][i] = -inf;
          }
        }
      }
    }
    //puts("bellman done");
    while (q--) {
      int u, v;
      scanf("%lld %lld", &u, &v);
      if (dist[u][v] >= inf) {
        puts("Impossible");
        continue;
      }
      if (dist[u][v] <= -inf) {
        puts("-Infinity");
        continue;
      }
      printf("%lld\n", dist[u][v]);
    }
    puts("");
  }

  return 0;
}
