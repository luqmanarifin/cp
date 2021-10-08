#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<pair<int, int>> edge[N];
int g[N], done[N];
char s[15];

bool can(int now, int c) {
  if (g[now] != -1) return g[now] == c;
  g[now] = c;
  for (auto it : edge[now]) {
    if (!can(it.first, c ^ it.second)) return 0;
  }
  return 1;
}

pair<int, int> dfs(int now) {
  if (done[now]) return {0, 0};
  done[now] = 1;
  int tot = 1, one = g[now];
  for (auto it : edge[now]) {
    auto ret = dfs(it.first);
    tot += ret.first;
    one += ret.second;
  }
  return {tot, one};
}

void clear(int n) {
  for (int i = 1; i <= n; i++) {
    edge[i].clear();
    g[i] = -1;
    done[i] = 0;
  }
}

int main() {
  memset(g, -1, sizeof(g));
  memset(done, 0, sizeof(done));

  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    while (m--) {
      int u, v;
      scanf("%d %d %s", &u, &v, s);
      int c = (s[0] == 'i');
      edge[u].emplace_back(v, c);
      edge[v].emplace_back(u, c);
    }
    bool solved = 1;
    for (int i = 1; i <= n; i++) {
      if (g[i] != -1) continue;
      if (!can(i, 0)) {
        solved = 0;
        break;
      }
    }
    if (!solved) {
      printf("-1\n");
      clear(n);
      continue;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      auto ret = dfs(i);
      ans += max(ret.second, ret.first - ret.second);
    }
    printf("%d\n", ans);
    clear(n);
  }

  return 0;
}
