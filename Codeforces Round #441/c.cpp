#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> a[N];
vector<int> adj[N], rev[N];
vector<int> ans;
int col[N];

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis;
int cntr, numCC;

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
    int cnt = 0;
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      cnt++;
      //printf(" %d", u);
      if(u == v)
        break;
    }
    if (cnt > 1) {
      puts("No");
      exit(0);
    }
  }
}

void dfs(int now) {
  if (col[now]) return;
  col[now] = 1;
  ans.push_back(now);
  for (auto it : rev[now]) dfs(it);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    while (v--) {
      int k;
      scanf("%d", &k);
      a[i].push_back(k);
    }
  }
  for (int i = 1; i < n; i++) {
    int sz = min(a[i-1].size(), a[i].size());
    for (int j = 0; j < sz; j++) {
      if (a[i-1][j] != a[i][j]) {
        adj[a[i-1][j]].push_back(a[i][j]);
        rev[a[i][j]].push_back(a[i-1][j]);
        goto SIP;
      }
    }
    if (a[i-1].size() > a[i].size()) {
      puts("No");
      return 0;
    }
    SIP:;
  }
  
// In MAIN();
  num.assign(m + 1, -1);
  low.assign(m + 1, 0);
  vis.assign(m + 1, 0);
  cntr = numCC = 0;
  for(int i = 1; i <= m; i++)
    if(num[i] == -1)
      tarjanSCC(i);
    
  for (int i = 1; i <= m; i++) {
    for (auto it : adj[i]) {
      if (i > it) {
        dfs(i);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (auto it : adj[i]) {
      if (i > it && col[i] == col[it]) {
        puts("No");
        return 0;
      }
    }
  }
  
  puts("Yes");
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%d ", it);
  return 0;
}
