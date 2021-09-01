#include <bits/stdc++.h>

using namespace std;

const int N = 55;

vector<int> edge[N];
int c[N], p[N], leaf[N], vis[N], b[N];

void dfs(int now, int bef, int branch) {
  // printf("dfs %d %d\n", now, bef);
  int child = 0;
  p[now] = bef;
  b[now] = branch;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dfs(it, now, now == 1? it : branch);
    child++;
  }
  if (child == 0) {
    leaf[now] = 1;
    // printf("leaf %d\n", now);
  }
}

int cur;

void solve(int now) {
  while (now != 0) {
    if (!vis[now]) {
      vis[now] = 1;
      cur += c[now];
    }
    now = p[now];
  }
}

void reset() {
  memset(vis, 0, sizeof(vis));
  cur = 0;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < N; i++) edge[i].clear();
    memset(leaf, 0, sizeof(leaf));
    memset(p, 0, sizeof(p));
    memset(b, 0, sizeof(b));

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", c + i);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    dfs(1, 0, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (!leaf[i]) continue;
      reset();
      solve(i);
      ans = max(ans, cur);
      for (int j = 1; j <= n; j++) {
        if (!leaf[j]) continue;
        if (b[i] != b[j]) {
          reset();
          solve(i);
          solve(j);
          ans = max(ans, cur);
        }
      }
    }
    printf("Case #%d: %d\n", tt, ans);
  }

  return 0;
}
