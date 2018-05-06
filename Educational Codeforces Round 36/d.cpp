
#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int M = 1e5 + 5;

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis;
int cntr, numCC;
vector<int> adj[N], el[N];
int par[N];

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
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      par[u] = numCC;
      el[numCC].push_back(u);
      if(u == v)
        break;
    }
    ++numCC;
  }
}

int to[N], ke[M];
vector<int> edge[N];

// 1 ada siklik
bool siklik(int id, int haram) {
  memset(to, 0, sizeof(to));
  for (auto i : el[id]) {
    for (auto it : edge[i]) {
      if (it == haram) continue;
      to[ke[it]]++;
    }
  }
  int done = 0;
  queue<int> q;
  for (auto i : el[id]) if (to[i] == 0) q.push(i);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    done++;
    for (auto it : edge[now]) {
      if (it == haram) continue;
      to[ke[it]]--;
      if (to[ke[it]] == 0) {
        q.push(ke[it]);
      }
    }
  }
  return done < el[id].size();
}

bool can(int id) {
  int pt = 0;
  for (auto it : el[id]) {
    for (auto jt : adj[it]) {
      if (par[jt] == id) {
        ke[pt] = jt;
        edge[it].push_back(pt);
        pt++;
        to[jt]++;
      }
    }
  }
  for (auto i : el[id]) {
    for (auto it : edge[i]) {
      if (to[ke[it]] == 1) {
        if (!siklik(id, it)) return 1;
      }
    }
  }
  return 0;
}  

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
  }
  num.assign(N, -1);
  low.assign(N, 0);
  vis.assign(N, 0);
  cntr = numCC = 0;
  for(int i = 1; i <= n; i++)
    if(num[i] == -1)
      tarjanSCC(i);
  
  int cyc = 0;
  for (int i = 0; i < numCC; i++) {
    if (el[i].size() > 1) {
      if (cyc) {
        puts("NO");
        return 0;
      }
      cyc = 1;
      if (!can(i)) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  return 0;
}
