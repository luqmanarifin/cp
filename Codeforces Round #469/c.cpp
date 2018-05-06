
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

// input
int u[N], c1[N], c2[N];

vector<int> edge[N];            // node
vector<int> el[N];              // supernode
int node[N];                    // node
int super_edges[N];             // supernode

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis;
int cntr, numCC;

void tarjanSCC(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : edge[v]) {
    if(num[u] == -1)
      tarjanSCC(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      el[numCC].push_back(u);
      node[u] = numCC;
      if(u == v)
        break;
    }
    ++numCC;
  }
}

int main() {
  int n, m, h;
  scanf("%d %d %d", &n, &m, &h);
  for (int i = 1; i <= n; i++) scanf("%d", u + i);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", c1 + i, c2 + i);
    if ((u[c1[i]] + 1) % h == u[c2[i]]) {
      edge[c1[i]].push_back(c2[i]);
    }
    if ((u[c2[i]] + 1) % h == u[c1[i]]) {
      edge[c2[i]].push_back(c1[i]);
    }
  }
  // In MAIN();
  num.assign(n + 1, -1);
  low.assign(n + 1, 0);
  vis.assign(n + 1, 0);
  cntr = numCC = 0;
  for(int i = 1; i<=n; i++)
    if(num[i] == -1)
      tarjanSCC(i);

  for (int i = 1; i <= n; i++) {
    for (auto it : edge[i]) {
      if (node[i] != node[it]) {
        super_edges[node[i]]++;
      }
    }
  }
  int ans = 1e9, at = -1;
  for (int i = 0; i < numCC; i++) {
    if (super_edges[i] == 0 && el[i].size() < ans) {
      ans = el[i].size();
      at = i;
    }
  }  
  printf("%d\n", ans);
  for (auto it : el[at]) printf("%d ", it);
    
  return 0;
}
