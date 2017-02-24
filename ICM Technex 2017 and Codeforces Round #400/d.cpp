#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], bef[N];

vector<pair<int, int>> edge[N];
int col[N];

int dfs(int now, int val) {
  if (col[now] != -1) {
    if (col[now] != val) return 1;
    return 0;
  }
  col[now] = val;
  for (auto it : edge[now]) {
    if (dfs(it.first, val ^ it.second ^ 1)) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= m; i++) {
    int len;
    scanf("%d", &len);
    while (len--) {
      int v;
      scanf("%d", &v);
      if (bef[v] == 0) {
        bef[v] = i;
      } else {
        edge[i].emplace_back(bef[v], a[v]);
        edge[bef[v]].emplace_back(i, a[v]);
      }
    }
  }
  memset(col, -1, sizeof(col));
  for (int i = 1; i <= m; i++) {
    if (col[i] == -1) {
      if (dfs(i, 0)) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  return 0;
}