#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

vector<int> g[N];
vector<int> dag[N];
int din[N];
int num[N], low[N], vis[N], com[N], ncom = 0, cntr = 0;
vector<int> S;
void dfs(int v) {
  num[v] = low[v] = ++cntr;
  S.push_back(v);
  vis[v] = 1;
  for (int u : g[v]) {
    if (num[u] == -1)
      dfs(u);
    if (vis[u])
      low[v] = min(low[v], low[u]);
  }
  if (num[v] == low[v]) {
    while (!S.empty()) {
      int u = S.back(); S.pop_back();
      com[u] = ncom;
      vis[u] = 0;
      if (u == v) break;
    }
    ++ncom;
  }
}

bitset<N> can[N];
int aft[N], bef[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int sum = n * 2 - 1;
  for (int i = 0; i < m; ++i) { 
    int u, v;
    scanf("%d %d", &u, &v);
    if (u < 0) u = sum + (u + 1);
    else --u;
    if (v < 0) v = sum + (v + 1);
    else --v;
    g[sum-u].push_back(v);
    g[sum-v].push_back(u);
  }
  memset(num, -1, sizeof num);
  ncom = 0;
  memset(vis, 0, sizeof vis);
  for (int i = 0; i <= sum; ++i) {
    if (num[i] != -1) continue;
    dfs(i);
  }
  // cek unsatisfiable
  for (int i = 0; i <= sum; ++i) {
    if (com[i] == com[sum-i]) {
      puts("0");
      return 0;
    }
  }
  for (int i = 0; i <= sum; ++i) {
    for (int u : g[i]) if (com[i] != com[u]) {
      dag[com[i]].push_back(com[u]);
      ++din[com[u]];
    }
  }
  stack<int> st;
  for (int i = 0; i < ncom; ++i) if (din[i] == 0)
    st.push(i);
  vector<int> topo;
  while (!st.empty()) {
    int v = st.top(); st.pop();
    topo.push_back(v);
    for (int u : dag[v]) {
      --din[u];
      if (din[u] == 0)
        st.push(u);
    }
  }
  for (int i = 0; i <= sum; ++i) {
    if (i < n)
      bef[com[i]] = 1;
    else
      aft[com[i]] = 1;
  }
  for (int i = 0; i < ncom; ++i)
    can[i][i] = 1;
  for (int v : topo) {
    for (int u : dag[v])
      bef[u] |= bef[v];
  }
  for (int i = (int)topo.size()-1; i >= 0; --i) {
    int v = topo[i];
    for (int u : dag[v]) {
      can[v] = (can[v] | can[u]);
      aft[v] |= aft[u];
    }
  }
  for (int i = 0; i < n; ++i) {
    int u = com[i], v = com[sum-i];
    if (can[u][v] && bef[u] && aft[v]) {
      puts("1");
      return 0;
    }
    swap(u, v);
    if (can[u][v] && bef[u] && aft[v]) {
      puts("1");
      return 0;
    }
  }
  for (int i = 0; i < m; ++i) {
    int u = com[i], v = com[sum-i];
    if (aft[u] && aft[v] && bef[u] && bef[v]) {
      puts("2");
      return 0;
    }
  }
  puts("-1");
  return 0;
}