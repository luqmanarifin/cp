#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int inf = 1e9;

bool good[N];
int u[N], v[N];

int dist[N], bef[N];
vector<int> edge[N];

int main() {
  int n, k, d;
  scanf("%d %d %d", &n, &k, &d);
  for (int i = 1; i <= k; i++) {
    int v;
    scanf("%d", &v);
    good[v] = 1;
  }
  for (int i = 1; i < n; i++) {
    scanf("%d %d", u + i, v + i);
    if (u[i] > v[i]) swap(u[i], v[i]);
    edge[u[i]].push_back(v[i]);
    edge[v[i]].push_back(u[i]);
  }
  fill(dist, dist + N, inf);
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (good[i]) {
      dist[i] = 0;
      q.push(i);
    }
  }
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto it : edge[now]) {
      if (dist[it] > dist[now] + 1) {
        dist[it] = dist[now] + 1;
        q.push(it);
        bef[it] = now;
      }
    }
  }
  set<pair<int, int>> important;
  for (int i = 1; i <= n; i++) {
    if (bef[i]) {
      int u = i;
      int v = bef[i];
      if (u > v) swap(u, v);
      important.insert({u, v});
    }
  }
  vector<int> ans;
  for (int i = 1; i < n; i++) {
    if (!important.count({u[i], v[i]})) {
      ans.push_back(i);
    }
  }
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%d ", it);
  return 0;
}
