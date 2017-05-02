#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int inf = 1e9;
const double PI = acos(-1.0);

vector<int> edge[N];
vector<pair<double, int>> near[N];
int x[N], y[N];
bool done[N];
int ans[N];

void dfs(int now_node, int now_point, int bef_node, double from) {
  if (from > PI) from -= PI;
  ans[now_node] = now_point;
  done[now_point] = 1;
  int i = lower_bound(near[now_point].begin(), near[now_point].end(), make_pair(from, -1)) - near[now_point].begin();
  for (auto it : edge[now_node]) {
    if (it == bef_node) continue;
    while (done[near[now_point][i].second]) i = (i + 1) % near[now_point].size();
    dfs(it, near[now_point][i].second, now_node, near[now_point][i].first);
    i = (i + 1) % near[now_point].size();
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) scanf("%d %d", x + i, y + i);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      int tx = x[j] - x[i];
      int ty = y[j] - y[i];
      near[i].emplace_back(atan2(ty, tx), j);
    }
    sort(near[i].begin(), near[i].end());
    for (int j = 0; j < n - 1; j++) {
      auto it = near[i][j];
      near[i].emplace_back(it.first + PI, it.second);
    }
  }
  pair<int, int> best = {inf, inf};
  int p = -1;
  for (int i = 1; i <= n; i++) {
    pair<int, int> cur = {x[i], y[i]};
    if (cur < best) {
      best = cur;
      p = i;
    }
  }
  dfs(1, p, 0, -inf);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
