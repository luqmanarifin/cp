#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<pair<int, int>> edge[N];
int a[N];

int dfs(int now, int c) {
  if (a[now] != -1) return a[now] == c;
  a[now] = c;
  for (auto it : edge[now]) {
    if (dfs(it.first, c ^ it.second) == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  memset(a, -1, sizeof(a));
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
      int u, v, c;
      scanf("%d %d %d", &u, &v, &c);
      edge[u].emplace_back(v, c);
      edge[v].emplace_back(u, c);
    }
    bool done = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == -1) {
        if (dfs(i, 0) == 0) {
          puts("no");
          done = 1;
          break;
        }
      }
    }
    if (!done) puts("yes");
    
    for (int i = 1; i <= n; i++) {
      edge[i].clear();
      a[i] = -1;
    }
  }
  return 0;
}