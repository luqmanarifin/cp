#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, LG = 20;

int node[N], st[N], en[N], lv[N], cntr = 0;

vector<int> g[N];

void dfs(int v, int par = -1) {
  node[cntr] = v;
  st[v] = cntr++;
  for (int u : g[v]) {
    if (u == par) continue;
    lv[u] = lv[v] + 1;
    dfs(u, v);
    node[cntr++] = v;
  }
  en[v] = cntr;
}

int sp[LG][N];
int get_sp(int l, int r) {
  if (l > r) swap(l, r);
  int len = r-l + 1;
  int lg = 31 - __builtin_clz(len);
  int le = sp[lg][l], ri = sp[lg][r-(1 << lg) + 1];
  return lv[le] < lv[ri] ? le : ri;
}

int lca(int u, int v) {
  return get_sp(st[u], st[v]);
}

int dist(int u, int v) {
  int a = lca(u, v);
  return lv[u] + lv[v] - 2 * lv[a];
}

bool ancestor(int u, int v) {
  return st[u] <= st[v] && en[v] <= en[u];
}

int sz[N], live[N], big[N], assign[N];

void dfs_centroid(int v, int par, int x) {
  assign[v] = x;
  sz[v] = 1;
  big[v] = -1;
  for (int u : g[v]) {
    if (!live[u]) continue;
    if (u == par) continue;
    dfs_centroid(u, v, x);
    sz[v] += sz[u];
    if (big[v] == -1 || sz[big[v]] < sz[u])
      big[v] = u;
  }
}

bool on_path(int u, int w, int v) {
  int a = lca(u, v);
  if (!ancestor(a, w)) return false;
  return ancestor(w, u) || ancestor(w, v);
}

vector<pair<int, int> > * edge[N];

bool centroid(int v) {
  int asli = v;
  dfs_centroid(v, -1, 0);
  int tot = sz[v];
  while (big[v] != -1 && 2 * sz[big[v]] >= tot) v = big[v];
  edge[v] = edge[asli];
  live[v] = 0;
  for (int u : g[v]) {
    if (!live[u]) continue;
    dfs_centroid(u, v, u);
    edge[u] = new vector<pair<int, int> > ();
  }
  vector<pair<int, int> > contain;
  pair<int, int> best = {v, v};
  int best_dist = -1;
  for (auto it : * edge[v]) {
    if (on_path(it.first, v, it.second)) {
      contain.push_back(it);
      int d = dist(it.first, it.second);
      if (d > best_dist)
        best_dist = d, best = it;
    }
    else
      edge[assign[it.first]]->push_back(it);
  }
  for (auto it : contain) {
    if (!on_path(best.first, it.first, best.second)) return false;
    if (!on_path(best.first, it.second, best.second)) return false;
  }
  for (int u : g[v]) {
    if (!live[u]) continue;
    int res = centroid(u);
    if (!res) return false;
  }
  return true;
}

int main() {
  int n, f;
  scanf("%d %d", &n, &f);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cntr = 0;
  lv[0] = 0;
  dfs(0);
  for (int i = 0; i < cntr; ++i)
    sp[0][i] = node[i];
  for (int i = 0; i + 1 < LG; ++i) {
    for (int j = 0; j + (1 << (i+1)) <= cntr; ++j) {
      int le = sp[i][j], ri = sp[i][j+(1<<i)];
      sp[i+1][j] = lv[le] < lv[ri] ? le : ri;
    }
  }
  edge[0] = new vector<pair<int, int> > ();
  for (int i = 0; i < f; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    edge[0]->emplace_back(u, v);
  }
  memset(live, 1, sizeof live);
  bool ans = centroid(0);
  puts(ans ? "Yes" : "No");
  return 0;
}