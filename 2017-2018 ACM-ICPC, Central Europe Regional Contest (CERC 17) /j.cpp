#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector<int> g[N];
int sz[N], cnt[N];

void dfs(int v, int par = -1) {
  sz[v] = 1;
  for (int u : g[v]) if (u != par) {
    dfs(u, v);
    sz[v] += sz[u];
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v); --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  for (int i = 0; i < n; ++i) {
    ++cnt[sz[i]];
  }
  bool first = 1;
  for (int i = 1; i < n; ++i) {
    int banyak = i+1;
    if (n % banyak) continue;
    int cur = 0;
    int s = n / banyak;
    for (int j = s; j <= n; j += s)
      cur += cnt[j];
    if (cur == banyak) {
      if (!first)
        printf(" ");
      printf("%d", i);
      first = 0;
    }
  }
  printf("\n");
  return 0;
}
