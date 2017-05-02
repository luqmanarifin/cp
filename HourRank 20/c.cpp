#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n, q, k, cnt[N], ans[N];
vector<int> edge[N];

void dfs(int now, int bef) {
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dfs(it, now);
    cnt[now] += cnt[it];
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  scanf("%d", &q);
  while (q--) {
    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
      int u;
      scanf("%d", &u);
      cnt[u]++;
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) ans[cnt[i]]++;
    for (int i = 0; i <= k; i++) printf("%d ", ans[i]); printf("\n");
  }

  return 0;
}
