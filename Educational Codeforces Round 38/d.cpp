
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

// cost - node - ok
priority_queue<pair<long long, int>> pq;
vector<pair<int, long long>> edge[N];
long long a[N], d[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v; long long w;
    scanf("%d %d %lld", &u, &v, &w);
    w *= 2;
    edge[u].emplace_back(v, w);
    edge[v].emplace_back(u, w);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    d[i] = a[i];
    pq.emplace(-a[i], i);
  }
  while (!pq.empty()) {
    long long cost; int now;
    tie(cost, now) = pq.top();
    cost = -cost;
    pq.pop();
    if (d[now] != cost) continue;
    for (auto it : edge[now]) {
      long long ncos = cost + it.second;
      int near = it.first;
      if (d[near] > ncos) {
        d[near] = ncos;
        pq.emplace(-d[near], near);
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%lld ", d[i]);

  return 0;
}
