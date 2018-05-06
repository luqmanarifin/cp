#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> edge[N];
map<pair<int, int>, bool> ada;

vector<int> st;
bool vis[N];

void dfs(int now, int bef) {
  vis[now] = 1;
  st.push_back(now);
  for (auto it : edge[now]) {
    if (it == bef) continue;
    if (!vis[it]) dfs(it, now);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
    ada[{u, v}] = ada[{v, u}] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      st.clear();
      dfs(i, -1);
      int edges = 0;
      bool ok = 1;
      for (int j = 0; j < st.size(); j++) {
        if (!ada[{st[j], st[(j + 1) % st.size()]}]) {
          ok = 0;
        }
        edges += edge[st[j]].size();
      }
      ok &= (edges == 2 * st.size());
      ans += ok;
    }
  }
  cout << ans << endl;
  return 0;
}
