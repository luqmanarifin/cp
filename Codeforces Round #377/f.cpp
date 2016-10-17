#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

vector<int> adj[N];

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis;
int cntr, numCC;
vector<int> cc[N];
int comp[N];

vector<int> edge[N];
int to[2 * N], flipped[N];

void tarjanSCC(int v, int bef) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : adj[v]) {
    if (u == bef) continue;
    if(num[u] == -1)
      tarjanSCC(u, v);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      cc[numCC].push_back(u);
      comp[u] = numCC;
      if(u == v)
        break;
    }
    numCC++;
  }
}

bool done[N];

void do_putar(int now) {
  if (done[now]) return;
  done[now] = 1;
  for (auto id : edge[now]) {
    if (flipped[id / 2] == -1 && comp[now] == comp[to[id]]) {
      flipped[id / 2] = id % 2;
      do_putar(to[id]);
    }
  }
}

void do_tree(int now) {
  if (done[now]) return;
  done[now] = 1;
  for (auto id : edge[now]) {
    if (comp[now] == comp[to[id]]) {
      do_tree(to[id]);
    } else {
      if (flipped[id / 2] == -1) {
        flipped[id / 2] = 1 - (id % 2);
        do_tree(to[id]);
      }
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    
    edge[u].push_back(i * 2);
    edge[v].push_back(i * 2 + 1);
    to[i * 2] = v;
    to[i * 2 + 1] = u;
  }
  num.assign(n + 1, -1);
  low.assign(n + 1, 0);
  vis.assign(n + 1, 0);
  cntr = numCC = 0;
  for(int i = 1; i<=n; i++)
    if(num[i] == -1)
      tarjanSCC(i, -1);
    
  memset(flipped, -1, sizeof(flipped));
  memset(done, 0, sizeof(done));
  int ans = 0, at = -1;
  for (int i = 0; i < numCC; i++) {
    do_putar(cc[i][0]);
    if (cc[i].size() > ans) {
      ans = cc[i].size();
      at = i;
    }
  }
  memset(done, 0, sizeof(done));
  do_tree(cc[at][0]);
  printf("%d\n", ans);
  for (int i = 0; i < m; i++) {
    int u, v;
    if (flipped[i] == 0) {
      u = to[i * 2 + 1];
      v = to[i * 2];
    } else {
      v = to[i * 2 + 1];
      u = to[i * 2];
    }
    printf("%d %d\n", u, v);
  }

  return 0;
}
