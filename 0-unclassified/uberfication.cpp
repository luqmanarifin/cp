#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

vector<int> num, low, S, vis, adj[N];
int cntr, numCC;

bool bad[N], done[N];
vector<int> edge[N];
int cnt[N], root, comp[N];
long long ans;

void tarjanSCC(int v, int p) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : adj[v]) {
    if(u == p) continue;
    if(num[u] == -1) tarjanSCC(u, v);
    if(vis[u]) {
      low[v] = min(low[v], low[u]);
    }
  }
  if(low[v] == num[v]) {
    vector<int> d;
    ++numCC;
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      comp[u] = numCC;
      d.push_back(u);
      if(u == v) {
        break;
      }
    }
    if((int) d.size() > 1) {
      for(auto it : d) {
        bad[it] = 1;
      }
    }
  }
}

void count(int now, int p) {
  cnt[now] = 1;
  for(auto it : edge[now]) {
    if(it == p) continue;
    count(it, now);
    cnt[now] += cnt[it];
  }
}

void dfs(int now, int p) {
  done[now] = 1;
  for(auto it : edge[now]) {
    if(it == p) continue;
    dfs(it, now);
    ans += 1LL * cnt[it] * (cnt[root] - cnt[it]);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    num.clear();
    low.clear();
    S.clear();
    vis.clear();
    for(int i = 0; i < N; i++) {
      adj[i].clear();
      edge[i].clear();
    }
    memset(comp, 0, sizeof(comp));
    memset(bad, 0, sizeof(bad));
    memset(done, 0, sizeof(done));
    memset(cnt, 0, sizeof(cnt));
    ans = root = 0;
    
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pair<int, int>> edges;
    while(m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
      edges.emplace_back(u, v);
    }
    num.assign(n + 1, -1);
    low.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    cntr = numCC = 0;
    for(int i = 1; i <= n; i++) {
      if(num[i] == -1) {
        tarjanSCC(i, 0);
      }
    }
    for(auto it : edges) {
      int u = it.first;
      int v = it.second;
      if(bad[u] && bad[v]) {
        if(comp[u] != comp[v]) {
          edge[u].push_back(v);
          edge[v].push_back(u);
        }
      } else {
        edge[u].push_back(v);
        edge[v].push_back(u);
      }
    }
    for(int i = 1; i <= n; i++) {
      if(!done[i] && !bad[i]) {
        root = i;
        count(i, 0);
        dfs(i, 0);
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}
