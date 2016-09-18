#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

bool f[N][N];
vector<int> edge[N];
int a[N];

int dfs(int now, int c) {
  if (a[now] != -1) {
    return a[now] != c;
  }
  a[now] = c;
  for (auto it : edge[now]) {
    if (dfs(it, c ^ 1)) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  memset(a, -1, sizeof(a));
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      f[u][v] = 1;
      f[v][u] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (f[i][j] == 0) {
          edge[i].push_back(j);
          edge[j].push_back(i);
        }
      }
    }
    bool bad = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == -1) {
        if (dfs(i, 0)) {
          bad = 1;
          puts("NO");
          break;
        }
      }
    }
    if (!bad) puts("YES");
    for (int i = 1; i <= n; i++) {
      edge[i].clear();
      a[i] = -1;
      for (int j = 1; j <= n; j++) {
        f[i][j] = 0;
      }
    }    
  }

  return 0;
}
