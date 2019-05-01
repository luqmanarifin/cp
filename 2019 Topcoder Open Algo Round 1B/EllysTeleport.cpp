#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

vector<int> adj[N], el[N];
int comp[N], ke[N];

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
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      el[numCC].push_back(u);
      comp[u] = numCC;
      if(u == v)
        break;
    }
    ++numCC;
  }
}

int h[N];

int got[N];

void dfs(int now) {
  if (got[now] != -1) return;
  got[now] = 1;
  for (auto it : adj[now]) {
    dfs(it);
    got[now] = max(got[now], got[it] + 1);
  }
}

class EllysTeleport {
public:
  int getMax(int n, int h1, int a, int b, int p, int q, int m) {
    h[0] = h1;
    for (int i = 1; i < n; i++) {
      h[i] = (1LL * h[i-1] * a + b) % m;
    }
    set<pair<int, int> > s;
    for (int i = 0; i < n; i++) {
      s.insert(make_pair(h[i], i));
    }
    for (int i = 0; i < n; i++) {
      long long v = (1LL * h[i] * p + q) % m;
      auto it = s.lower_bound(make_pair(v + 1, -1));
      if (it != s.begin()) {
        it--;
        int to = it->second;
        adj[i].push_back(to);
      }
    }

    num.assign(n, -1);
    low.assign(n, 0);
    vis.assign(n, 0);
    cntr = numCC = 0;
    for(int i = 0; i < n; i++)
      if(num[i] == -1)
        tarjanSCC(i);

    memset(got, -1, sizeof(got));
    for (int i = 0; i < numCC; i++) {
      if (el[i].size() > 1) {
        for (auto it : el[i]) {
          got[it] = el[i].size();
        }
      }
    }
    for (int i = 0; i < n; i++) dfs(i);

    int ans = -1;
    for (int i = 0; i < n; i++) ans = max(ans, got[i]);
    return ans;
  }
};

// int main() {
//   // int l = 0;
//   // int r = 0;

//   // EllysTeleport EllysTeleport;
//   // cout << EllysTeleport.getMax() << endl;

//   return 0;
// }
