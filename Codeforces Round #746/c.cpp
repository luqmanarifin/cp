#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> edge[N];
int p[N], sub[N], a[N];

void add(int u, int v) {
  edge[u].push_back(v);
  edge[v].push_back(u);
}

void remove(int u, int v) {
  vector<int> tmp;
  for (auto it : edge[u]) if (it != v) tmp.push_back(it);
  edge[u] = tmp;

  tmp.clear();
  for (auto it : edge[v]) if (it != u) tmp.push_back(it);
  edge[v] = tmp;
}

int dfs(int goal, int now, int bef = -1) {
  sub[now] = a[now];
  p[now] = bef;
  for (auto it : edge[now]) {
    if (bef == it) continue;
    int ret = dfs(goal, it, now);
    if (ret != 0) return ret;
    sub[now] ^= sub[it];
  }
  return sub[now] == goal? now : 0;
}

void clear(int n) {
  for (int i = 1; i <= n; i++) edge[i].clear();
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      tot ^= a[i];
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      add(u, v);
    }
    if (tot == 0) {
      puts("YES");
      clear(n);
      continue;
    }
    if (k == 2 || n == 2) {
      puts("NO");
      clear(n);
      continue;
    }
    int now = dfs(tot, 1);
    // printf("now %d\n", now);
    if (now <= 1) {
      puts("NO");
      clear(n);
      continue;
    }
    remove(now, p[now]);
    now = dfs(tot, 1);
    if (now <= 1) {
      puts("NO");
      clear(n);
      continue;
    }
    puts("YES");
    clear(n);
  }
  return 0;
}
