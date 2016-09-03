#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

vector<int> edge[N];
int a[N];

int dfs(int now, int bef, int c) {
  if (a[now] != -1) {
    if (a[now] != c) return -1;
    return 0;
  }
  a[now] = c;
  for (int i = 0; i < edge[now].size(); i++) {
    int it = edge[now][i];
    if (dfs(it, now, c ^ 1)) {
      return -1;
    }
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) edge[i].clear();
    memset(a, -1, sizeof(a));
    
    int n, m;
    scanf("%d %d", &n, &m);
    while (m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    
    bool ada = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] != -1) continue;
      if (dfs(i, -1, 0)) {
        ada = 1;
        puts("NO");
        break;
      }
    }
    if (!ada) puts("YES");
  }

  return 0;
}
