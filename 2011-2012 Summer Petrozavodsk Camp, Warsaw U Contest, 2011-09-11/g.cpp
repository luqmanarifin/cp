#include <bits/stdc++.h>

using namespace std;

const int N = 3005;

set<int> edge[N];
bool adj[N][N];
int deg[N];

int main() {
  freopen("party.in", "r", stdin);
  freopen("party.out", "w", stdout);
  int n, m;
  scanf("%d %d", &n, &m);
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u][v] = adj[v][u] = 1;
    deg[u]++;
    deg[v]++;
  }
  set<int> s;
  for (int i = 1; i <= n; i++) {
    if (deg[i] >= 2*n/3 - 1) {
      s.insert(i);
    }
  }
  //printf("%d\n", s.size());
  for (auto i : s) {
    for (int j = 1; j <= n; j++) {
      if (adj[i][j] && s.count(j)) {
        edge[i].insert(j);
      }
    }
  }
  while (s.size() > n / 3) {
    //printf("%d\n", s.size());
    int smallest = 1e9, p = -1;
    for (auto it : s) {
      if (edge[it].size() < smallest) {
        smallest = edge[it].size();
        p = it;
      }
    }
    for (auto it : s) {
      edge[it].erase(p);
    }
    s.erase(p);
  }
  for (auto it : s) printf("%d ", it); printf("\n");
  return 0;
}
