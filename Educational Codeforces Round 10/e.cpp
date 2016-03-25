#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector<int> adj[N];
int gol[N], num_gol;

vector<int> num, low, S, vis;
int cntr, numCC;

void tarjanSCC(int v, int bef) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : adj[v]) {
    if(u == bef) continue;
    if(num[u] == -1)
      tarjanSCC(u, v);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      gol[u] = num_gol;
      if(u == v)
        break;
    }
    num_gol++;
  }
}

int u[N], v[N], c[N];
set<int> nice[N];
bool good[N];
vector<int> edge[N];
int par[N];

void dfs(int now, int bef) {
  for(auto it : edge[now]) {
    if(it == bef) continue;
    par[it] = now;
    dfs(it, now);
  }  
}

void check(int a, int lca) {
  int now = a;
  while(1) {
    if(good[now]) {
      puts("YES");
      exit(0);
    }
    if(now == lca) break;
    if(nice[now].count(par[now])) {
      puts("YES");
      exit(0);
    }
    now = par[now];
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d %d %d", u + i, v + i, c + i);
    adj[u[i]].push_back(v[i]);
    adj[v[i]].push_back(u[i]);
  }
  int a, b;
  scanf("%d %d", &a, &b);
  num.assign(n + 1, -1);
  low.assign(n + 1, 0);
  vis.assign(n + 1, 0);
  cntr = numCC = 0;
  for(int i = 1; i<=n; i++) {
    if(num[i] == -1)
      tarjanSCC(i, -1);
  }
  //for(int i = 1; i <= n; i++) printf("lala %d %d\n", i, gol[i]);
  for(int i = 0; i < m; i++) {
    if(gol[u[i]] != gol[v[i]]) {
      edge[gol[u[i]]].push_back(gol[v[i]]);
      edge[gol[v[i]]].push_back(gol[u[i]]);
    }
    if(c[i]) {
      if(gol[u[i]] == gol[v[i]]) {
        good[gol[u[i]]] = 1;
      } else {
        nice[gol[u[i]]].insert(gol[v[i]]);
        nice[gol[v[i]]].insert(gol[u[i]]);
      }
    }
  }
  /*
  for(int i = 0; i < num_gol; i++) {
    printf("%d : ", i);
    for(auto it : edge[i]) printf("%d ", it); printf("\n");
  }
  */
  a = gol[a];
  b = gol[b];
  memset(par, -1, sizeof(par));
  dfs(0, -1);
  
  set<int> anc;
  int root = a;
  while(root != -1) {
    anc.insert(root);
    root = par[root];
  }
  
  int lca = b;
  while(!anc.count(lca)) lca = par[lca];
  
  check(a, lca);
  check(b, lca);
  puts("NO");
  return 0;
}
