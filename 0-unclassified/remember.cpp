#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis, adj[N];
int cntr, numCC;
bool cyc[N];

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
    //printf("SCC %d :", ++numCC);
    vector<int> bad;
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      bad.push_back(u);
      if(u == v)
        break;
    }
    if(bad.size() > 1) {
      for(auto it : bad) cyc[it] = 1;
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
  }
  
  // In MAIN();
  num.assign(n + 1, -1);
  low.assign(n + 1, 0);
  vis.assign(n + 1, 0);
  cntr = numCC = 0;
  for(int i = 1; i<=n; i++)
    if(num[i] == -1)
      tarjanSCC(i);
    
  for(int i = 1; i <= n; i++) {
    if(i > 1) printf(" ");
    printf("%d", cyc[i]);
  }
  printf("\n");
  return 0;
}
