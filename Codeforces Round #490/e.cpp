#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

vector<int> adj[N], edge[N];
int comp[N];

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis;
int cntr, numCC;
int to[N];

void tarjanSCC(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : adj[v]) {
    if(num[u] == -1)
      tarjanSCC(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    // printf("SCC %d: ", numCC);
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      // printf(" %d", u);
      comp[u] = numCC;
      if(u == v)
        break;
    }
    numCC++;
  }
}

int main() {
  int n, m, s;
  scanf("%d %d %d", &n, &m, &s);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
  }

// In MAIN();
  num.assign(N, -1);
  low.assign(N, 0);
  vis.assign(N, 0);
  cntr = numCC = 0;
  for(int i = 1; i<=n; i++)
    if(num[i] == -1)
      tarjanSCC(i);

  set<pair<int, int>> all;
  for (int i = 1; i <= n; i++) {
    for (auto it : adj[i]) {
      if (comp[i] != comp[it] && !all.count(make_pair(comp[i], comp[it]))) {
        edge[comp[i]].push_back(comp[it]);
        all.insert(make_pair(comp[i], comp[it]));
      }
    }
  }
  for (int i = 0; i < numCC; i++) {
    for (auto it : edge[i]) {
      to[it]++;
    }
  }
  int ans = 0;
  for (int i = 0; i < numCC; i++) {
    if (i == comp[s]) continue;
    if (to[i] == 0) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
