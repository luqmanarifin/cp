#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int num[N], low[N], vis[N], cntr, numCC;
vector<int> S, edge[N], baru[N];
int bad[N], done[N];

void scc(int v, int p) {
  vis[v] = 1;
  low[v] = num[v] = ++cntr;
  S.push_back(v);
  for(auto u : edge[v]) {
    if(u == p) continue;
    if(num[u] == -1) {
      scc(u, v);
    }
    if(vis[u]) {
      low[v] = min(low[v], low[u]);
    }
  }
  if(low[v] == num[v]) {
    //printf("SCC %d :", ++numCC);
    bool siklik = (S.back() != v);
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      if(siklik) bad[u] = 1;
      //printf(" %d", u);
      if(u == v) break;
    }
    //printf("\n");
  }
}

int dfs(int now, int p) {
  done[now] = 1;
  int ret = 1;
  for(auto it : baru[now]) {
    if(it == p) continue;
    if(!done[it]) {
      ret += dfs(it, now);
    }
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    memset(num, -1, sizeof(num));
    memset(low, 0, sizeof(low));
    memset(vis, 0, sizeof(vis));
    memset(bad, 0, sizeof(bad));
    memset(done, 0, sizeof(done));
    S.clear();
    cntr = numCC = 0;
    for(int i = 0; i < N; i++) {
      edge[i].clear();
      baru[i].clear();
    }
    
    int n, m;
    scanf("%d %d", &n, &m);
    while(m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++) {
      if(num[i] == -1) {
        scc(i, -1);
      }
    }
    for(int i = 1; i <= n; i++) {
      if(bad[i]) continue;
      for(auto it : edge[i]) {
        if(bad[it]) continue;
        baru[i].push_back(it);
        baru[it].push_back(i);
      }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
      if(!done[i]) {
        int ret = dfs(i, -1);
        ans += ret * (ret - 1) / 2;
      }
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
