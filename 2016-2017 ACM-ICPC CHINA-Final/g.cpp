#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct node {
  node(int v) {
    ans = 1;
    col.insert({v, 1});
  }
  void join(node other) {
    for (auto it : other.col) {
      auto c = col.lower_bound(it.first, -1);
      int cnt = it.second;
      if (c->first == it.first) {
        cnt += c->second;
        col.erase(c);
      }
      col.insert({it.first, cnt});
    }
  }
  multiset<pair<int, int>> col;
  int ans;
};

int par[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

void reset() {
  for (int i = 0; i < N; i++) par[i] = i;
}

int a[N];
vector<pair<int, int>> ans[N];
int root[N];
node nodes[N];

int lift[N][20];
int cost[N][20];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    for (int i = 0; i < N; i++) ans[i].clear(), root[i] = i;
    
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    vector<tuple<int, int, int>> edges;
    for (int i = 1; i <= m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      edges.emplace_back(w, u, v);
    }
    for (int i = 1; i <= n; i++) {
      nodes[i] = nodes(a[i]);
      ans[i].emplace_back(0, 1);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 20; j++) {
        cost[i][j] = 2e9;
        lift[i][j] = -1;
      }
    }
    sort(edges.begin(), edges.end());
    reset();
    for (auto it : edges) {
      int u, v, w;
      tie(w, u, v) = it;
      if (find(u) != find(v)) {
        mst.push_back(it);
        if (nodes[])
      }
    }
    
    printf("Case #%d:\n", tc);
  }
  return 0;
}