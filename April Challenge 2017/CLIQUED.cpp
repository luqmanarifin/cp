#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

long long d[N];
vector<pair<int, int>> edge[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) edge[i].clear();
    fill(d, d + N, inf);
    
    int n, k, x, m, s;
    scanf("%d %d %d %d %d", &n, &k, &x, &m, &s);
    //puts("cok");
    for (int i = 0; i < m; i++) {
      int u, v, c;
      scanf("%d %d %d", &u, &v, &c);
      edge[u].emplace_back(v, c);
      edge[v].emplace_back(u, c);
    }
    //puts("asu");
    if (s <= k) for (int i = 1; i <= k; i++) d[i] = x;
    d[s] = 0;
    priority_queue<pair<long long, int>> pq;
    for (int i = 1; i <= n; i++) if (d[i] != inf) {
      pq.emplace(-d[i], i);
    }
    while (!pq.empty()) {
      long long cost;
      int now;
      tie(cost, now) = pq.top();
      cost = -cost;
      pq.pop();
      if (d[now] != cost) continue;
      //printf("%lld %d\n", cost, now);
      for (auto it : edge[now]) {
        long long ncos = cost + it.second;
        int near = it.first;
        if (ncos < d[near]) {
          d[near] = ncos;
          pq.emplace(-d[near], near);
        }
      }
    }
    long long best = inf;
    for (int i = 1; i <= k; i++) best = min(best, d[i]);
    for (int i = 1; i <= k; i++) d[i] = min(d[i], best + x);
    for (int i = 1; i <= n; i++) printf("%lld ", d[i]); printf("\n");
  }

  return 0;
}
