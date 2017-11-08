#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6, K = 6;

vector<vector<int> > dp[N];
vector<vector<int> > gm[N];
vector<int> dpdag[N];
vector<int> elem[N];

int n, m, ncomp;
vector<int> g[N], dag[N];
int din[N];
int num[N], low[N], vis[N], cntr, comp[N], pos[N];
vector<int> nodes;

void scc(int v) {
  num[v] = low[v] = cntr++;
  vis[v] = 1;
  nodes.push_back(v);
  for (int u : g[v]) {
    if (num[u] == -1)
      scc(u);
    if (vis[u])
      low[v] = min(low[v], low[u]);
  }
  if (num[v] == low[v]) {
    while (!nodes.empty()) {
      int u = nodes.back(); nodes.pop_back();
      pos[u] = elem[ncomp].size();
      comp[u] = ncomp;
      elem[ncomp].push_back(u); vis[u] = 0;
      if (u == v) break;
    }
    ncomp++;
  }
}

vector<vector<int> > mem;
void calc_dp(vector<vector<int > > & adj, vector<vector<int > > & res) {
  int k = adj.size();
  res.resize(k);
  for (int i = 0; i < k; i++)
    res[i].assign(k, 0);
  mem.resize(k);
  for (int i = 0; i < k; i++)
    mem[i].resize(1 << k);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++)
      for (int mask = 0; mask < (1 << k); mask++)
        mem[j][mask] = 0;
//    cerr << k << endl;
    queue<pair<int, int> > que;
    mem[i][1 << i] = 1;
    res[i][i] = 1;
    que.push(make_pair(i, 1 << i));
    while (!que.empty()) {
      auto it = que.front(); que.pop();
      int v = it.first, mask = it.second;
      res[i][v] = max(res[i][v], __builtin_popcount(mask));
      for (int j = 0; j < k; j++) {
        if (!adj[v][j] || (mask & (1 << j))) continue;
        int nmask = mask | 1 << j;
        if (mem[j][nmask]) continue;
        mem[j][nmask] = 1;
        que.push(make_pair(j, nmask));
      }
    }
  }
}

int main() {
  cntr = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
  }
  memset(vis, 0, sizeof vis);
  memset(num, -1, sizeof num);
  ncomp = 0;
  for (int i = 0; i < n; i++) if (num[i] == -1) {
    scc(i);
    if (nodes.size() != 0) {
      while (!nodes.empty()) {
        int u = nodes.back(); nodes.pop_back();
        pos[u] = elem[ncomp].size();
        comp[u] = ncomp;
        elem[ncomp].push_back(u); vis[u] = 0;
      }
      ncomp++;
    }
  }
  for (int i = 0; i < ncomp; i++) {
    int k = elem[i].size();
    gm[i].resize(k);
    for (int j = 0; j < k; j++)
      gm[i][j].assign(k, 0);
  }
  for (int i = 0; i < n; i++) {
    for (int u : g[i]) {
      if (comp[i] != comp[u]) continue;
      gm[comp[i]][pos[i]][pos[u]] = 1;
    }
  }
  for (int i = 0; i < ncomp; i++) {
    calc_dp(gm[i], dp[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int u : g[i]) {
      if (comp[u] == comp[i]) continue;
      dag[comp[i]].push_back(comp[u]);
      din[comp[u]]++;
    }
  }
  stack<int> st;
  for (int i = 0; i < ncomp; i++) {
    if (din[i]) continue;
    st.push(i);
  }
  vector<int> topo;
  while (!st.empty()) {
    int v = st.top(); st.pop();
    topo.push_back(v);
    for (int u : dag[v]) {
      din[u]--;
      if (din[u] == 0)
        st.push(u);
    }
  }
  int ans = 0;
  for (int i = (int)topo.size()-1; i >= 0; i--) {
    int c = topo[i];
    int k = elem[c].size();
    dpdag[c].assign(elem[c].size(), 1);
    vector<int> temp;
    temp.assign(k, 0);
    for (int j = 0; j < k; j++) {
      int v = elem[c][j];
      for (int u : g[v]) {
        if (comp[u] == c) continue;
        temp[j] = max(temp[j], dpdag[comp[u]][pos[u]]);
      }
    }
    for (int j = 0; j < k; j++) {
      for (int z = 0; z < k; z++)
        dpdag[c][j] = max(dpdag[c][j], dp[c][j][z] + temp[z]);
    }
    for (int j = 0; j < k; j++)
      ans = max(ans, dpdag[c][j]);
  }
  printf("%d\n", ans);
  return 0;
}
