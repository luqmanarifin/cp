#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const long long inf = 1e18;

vector<pair<int, long long>> edge[N];
int s[N], best[N];

long long dp[N][N]; // index - last bike

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
      edge[i].clear();
      best[i] = N;
      for (int j = 0; j < N; j++) dp[i][j] = inf;
    }
    while (m--) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      edge[u].emplace_back(v, w);
      edge[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++) scanf("%d", s + i);

    priority_queue<tuple<long long, int, int>> pq;  // cost - bike - index
    dp[1][s[1]] = 0;
    pq.emplace(0, -s[1], 1);
    while (!pq.empty()) {
      long long cost; int bike, now;
      tie(cost, bike, now) = pq.top();
      pq.pop();
      cost = -cost; bike = -bike;
      if (now == n) {
        printf("%lld\n", cost);
        break;
      }
      if (cost != dp[now][bike]) continue;
      if (bike > best[now]) continue;
      best[now] = min(best[now], bike);
      for (auto it : edge[now]) {
        int near = it.first;
        long long w = it.second;
        int next_bike = min(bike, s[now]);
        long long next_cost = cost + w * next_bike;
        if (next_cost < dp[near][next_bike]) {
          dp[near][next_bike] = next_cost;
          pq.emplace(-next_cost, -next_bike, near);
        }
      }
    }
  }  

  return 0;
}
