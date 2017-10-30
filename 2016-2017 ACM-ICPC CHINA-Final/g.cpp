#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;
const int BIT = 17;

struct node {
  node() {}
  node(int v) {
    ans = {1, -v};
    col.insert({v, 1});
  }
  void join(node other) {
    for (auto it : other.col) {
      auto c = col.lower_bound({it.first, -1});
      int cnt = it.second;
      if (c->first == it.first) {
        cnt += c->second;
        col.erase(c);
      }
      col.insert({it.first, cnt});
      ans = max(ans, make_pair(cnt, -it.first));
    }
  }
  set<pair<int, int>> col;
  pair<int, int> ans;
};

int a[N];
vector<pair<int, int>> ans[N];
int par[N];
node nodes[N];

int lift[N][BIT];
int cost[N][BIT];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) ans[i].clear(), par[i] = i;
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    vector<tuple<int, int, int>> edges;
    for (int i = 1; i <= m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      edges.emplace_back(w, u, v);
    }
    for (int i = 1; i <= n; i++) {
      nodes[i] = node(a[i]);
      ans[i].emplace_back(0, a[i]);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < BIT; j++) {
        cost[i][j] = 2e9;
        lift[i][j] = i;
      }
    }
    sort(edges.begin(), edges.end());
    int num = 0;
    for (auto it : edges) {
      int u, v, w;
      tie(w, u, v) = it;
      u = find(u);
      v = find(v);
      if (nodes[u].col.size() > nodes[v].col.size()) swap(u, v);
      if (u != v) {
        cost[u][0] = w;
        lift[u][0] = v;
        nodes[v].join(nodes[u]);
        par[u] = v;
        ans[v].emplace_back(w, -nodes[v].ans.second);
      }
    }
    for (int j = 1; j < BIT; j++) {
      for (int i = 1; i <= n; i++) {
        lift[i][j] = lift[lift[i][j-1]][j-1];
        cost[i][j] = cost[lift[i][j-1]][j-1];
      }
    }
    printf("Case #%d:\n", tc);
    int last = 0;
    int q;
    scanf("%d", &q);
    while (q--) {
      int x, w;
      scanf("%d %d", &x, &w);
      x ^= last;
      w ^= last;
      for (int j = BIT - 1; j >= 0; j--) {
        if (cost[x][j] <= w) {
          x = lift[x][j];
        }
      }
      int it = lower_bound(ans[x].begin(), ans[x].end(), make_pair(w, inf)) - ans[x].begin() - 1;
      last = ans[x][it].second;
      printf("%d\n", last);
    }
    //cerr << "DONE" << endl;
  }
  return 0;
}