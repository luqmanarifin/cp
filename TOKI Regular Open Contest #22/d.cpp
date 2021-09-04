#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

vector<pair<int, int>> edge[N]; // index - cost
vector<pair<int, int>> stu[N];  // index - cost
int p[N], a[N];
int n, m, k;

// finding student
long long d[N];

int find(int mid) {
  priority_queue<pair<long long, int>> pq;
  for (int i = 1; i <= n; i++) {
    if (i <= mid) {
      d[i] = 0;
      pq.emplace(0, i);
    } else {
      d[i] = inf;
    }
  }
  while (!pq.empty()) {
    int dist, now;
    tie(dist, now) = pq.top();
    pq.pop();
    dist = -dist;
    if (dist != d[now]) continue;

    for (auto it : edge[now]) {
      int near, cost;
      tie(near, cost) = it;
      int next_cost = dist + cost;
      if (next_cost < d[near]) {
        d[near] = next_cost;
        pq.emplace(-d[near], near);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (auto it : stu[i]) {
      int idx, aff;
      tie(idx, aff) = it;
      if (aff < d[i]) {
        ans = max(ans, idx);
      }
    }
  }
  return ans;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edge[u].emplace_back(v, w);
    edge[v].emplace_back(u, w);
  }
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d %d", p + i, a + i);
    stu[p[i]].emplace_back(i, a[i]);
  }

  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (find(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << find(l) << endl;
  return 0;
}
