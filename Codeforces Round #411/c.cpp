#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector<int> edge[N], s[N];
int ans[N];

void dfs(int now, int bef) {
  set<int> done;
  for (auto it : s[now]) done.insert(ans[it]);
  int k = 1;
  for (auto it : s[now]) if (ans[it] == 0) {
    while (done.count(k)) k++;
    ans[it] = k++;
  }
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dfs(it, now);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int col = 1;
  for (int i = 1; i <= n; i++) {
    int k;
    scanf("%d", &k);
    col = max(col, k);
    while (k--) {
      int u;
      scanf("%d", &u);
      s[i].push_back(u);
    }
  }
  col = max(col, 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= m; i++) if (ans[i] == 0) ans[i] = 1;
  printf("%d\n", col);
  for (int i = 1; i <= m; i++) printf("%d ", ans[i]);

  return 0;
}
