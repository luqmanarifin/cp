#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> edge[N];
int a[N], ans[N];
set<int> can[N];

void dfs(int now, int bef, int all) {
  ans[now] = *(can[now].rbegin());
  for (auto it : edge[now]) {
    if (it == bef) continue;
    for (auto v : can[now]) {
      can[it].insert(__gcd(v, a[it]));
    }
    can[it].insert(all);
    dfs(it, now, __gcd(all, a[it]));
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  can[1].insert(a[1]);
  can[1].insert(0);
  dfs(1, 0, a[1]);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}