#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> edge[N];
int par[N], sz[N], edges[N];

int find(int u) {
  return par[u] = par[u] == u? u : find(par[u]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return;
  par[u] = v;
  sz[v] += sz[u];
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < N; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
    merge(u, v);
  }
  for (int i = 1; i <= n; i++) {
    edges[find(i)] += edge[i].size();
  }
  bool full = 1;
  for (int i = 1; i <= n; i++) {
    int u = find(i);
    //printf("%d: %d %d=%I64d\n", i, u, edges[u], 1LL * sz[u] * (sz[u] - 1));
    if (1LL * sz[u] * (sz[u] - 1) != edges[u]) {
      full = 0;
    }
  }
  puts(full? "YES" : "NO");
  return 0;
}
