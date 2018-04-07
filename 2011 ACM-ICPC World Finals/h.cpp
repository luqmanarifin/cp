#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int num[N], low[N], childroot, artp[N], nblock, root, counter, n;
vector<pair<int, int>> edge, block[N], bridge;
vector<int> adj[N];

void dfs(int v, int bef = -1) {
  num[v] = low[v] = counter++;
  for (int u : adj[v]) {
    if (num[u] == -1) {
      edge.emplace_back(v, u);
      if (v == root)
        childroot++;
      dfs(u, v);
      if (childroot > 1 && v == root) {
        artp[v] = 1;
        while (edge.size() > 0) {
          auto it = edge.back(); edge.pop_back();
          block[nblock].push_back(it);
          if (it == make_pair(v, u))
            break;
        }
        nblock++;
      }
      if (low[u] >= num[v] && v != root) {
        artp[v] = 1;
        while (edge.size() > 0) {
          auto it = edge.back(); edge.pop_back();
          block[nblock].push_back(it);
          if (it == make_pair(v, u))
            break;
        }
        nblock++;
      }
      if (low[u] > num[v])
        bridge.emplace_back(u, v);
      low[v] = min(low[v], low[u]);
    }
    else if (bef != u && low[v] > num[u]) {
      low[v] = min(low[v], num[u]);
      edge.emplace_back(v, u);
    }
  }
}

int id[N];
set<int> art[N], nodes[N];
vector<int> edges[N];

int main() {
  int m;
  scanf("%d", &m);
  int tc = 0;
  while (m) {
    tc++;
    printf("Case %d: ", tc);
    for (int i = 0; i < N; i++) {
      num[i] = -1;
      low[i] = 0;
      artp[i] = 0;
      block[i].clear();
      adj[i].clear();
      art[i].clear();
      edges[i].clear();
      nodes[i].clear();
    }
    edge.clear();
    bridge.clear();
    childroot = 0;
    nblock = 0;
    counter = 0;
    n = 0;
    
    while (m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
      n = max(n, u);
      n = max(n, v);
    }
    
    //~ puts("baca");
    for (int i = 1; i <= n; i++) if (num[i] == -1) {
      root = i;
      childroot = 0;
      edge.clear();
      dfs(i);
      artp[i] = childroot > 1;
      if (edge.size() > 0) {
        while (edge.size() > 0) {
          auto it = edge.back(); edge.pop_back();
          block[nblock].push_back(it);
        }
        nblock++;
      }
    }
    //~ puts("asu");
    //~ printf("nblock %d\n", nblock);
    if (nblock == 1) {
      printf("%d %lld\n", 2, 1LL * n * (n - 1) / 2);
      scanf("%d", &m);
      continue;
    }
    int num_id = nblock;
    for (int i = 1; i <= n; i++) if (artp[i]) {
      id[i] = num_id++;
    }
    for (int i = 0; i < nblock; i++) {
      //~ printf("block %d\n", i);
      for (auto it : block[i]) {
        //~ printf("edge %d %d\n", it.first, it.second);
        if (artp[it.first]) {
          art[i].insert(it.first);
        }
        if (artp[it.second]) {
          art[i].insert(it.second);
        }
        nodes[i].insert(it.first);
        nodes[i].insert(it.second);
      }
    }
    
    for (int i = 0; i < nblock; i++) {
      for (auto it : art[i]) {
        //~ printf("block %d punya articulation %d\n", i, it);
        edges[i].push_back(id[it]);
        edges[id[it]].push_back(i);
      }
    }
    
    long long ans = 1;
    int leaf = 0;
    for (int i = 0; i < num_id; i++) {
      if (edges[i].size() == 1) {
        leaf++;
        ans *= (nodes[i].size() - 1);
      }
    }
    printf("%d %lld\n", leaf, ans);
    
    scanf("%d", &m);
  }
}

