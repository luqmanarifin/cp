#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

vector<int> edge[N];
int n, h[N], m[N], cnth[N], cntm[N], maxh;

void dfs(int now, int p, int lvl) {
  h[now] = m[now] = lvl;
  maxh = max(maxh, h[now]);
  for (auto it : edge[now]) {
    if (it == p) continue;
    dfs(it, now, lvl + 1);
    m[now] = max(m[now], m[it]);
  }
  cnth[h[now]]++;
  cntm[m[now]]++;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      edge[i].clear();
      m[i] = cnth[i] = cntm[i] = 0;
    }

    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    maxh = 0;
    dfs(1, 0, 1);
    int ans = n, bigger = n, base = 0;
    for (int lvl = 1; lvl <= maxh; lvl++) {
      bigger -= cnth[lvl];
      int cur = base + bigger;
      ans = min(ans, cur);
      base += cntm[lvl];
    }
    printf("%d\n", ans);
  }

  return 0;
}
