#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int inf = 1e9;
const double PI = acos(-1.0);

vector<int> edge[N];
int x[N], y[N], cnt[N];

int ans[N];

void pre(int now, int bef) {
  cnt[now] = 1;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    pre(it, now);
    cnt[now] += cnt[it];
  }
}

void dfs(int now_node, int now_point, int bef_node, vector<int> active) {
  ans[now_node] = now_point;
  vector<pair<double, int>> near;
  for (auto it : active) {
    if (it == now_point) continue;
    int tx = x[it] - x[now_point];
    int ty = y[it] - y[now_point];
    near.emplace_back(atan2(ty, tx), it);
  }
  sort(near.begin(), near.end());
  int p = 0;
  for (auto it : edge[now_node]) {
    if (it == bef_node) continue;
    vector<int> act;
    pair<int, int> best = {inf, inf};
    int mini = -1;
    for (int i = 0; i < cnt[it]; i++) {
      int id = near[p + i].second;
      pair<int, int> cur = {x[id], y[id]};
      if (cur < best) {
        best = cur;
        mini = id;
      }
      act.push_back(id);
    }
    dfs(it, mini, now_node, act);
    p += cnt[it];
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
  pair<int, int> best = {inf, inf};
  int p = -1;
  for (int i = 1; i <= n; i++) {
    pair<int, int> cur = {x[i], y[i]};
    if (cur < best) {
      best = cur;
      p = i;
    }
  }
  pre(1, 0);
  vector<int> active;
  for (int i = 1; i <= n; i++) active.push_back(i);
  dfs(1, p, 0, active);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
