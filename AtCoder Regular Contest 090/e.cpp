#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;
const long long mod = 1e9 + 7;

long long d0[N], d1[N];
long long w0[N], w1[N];
vector<pair<int, int>> edge[N];

void dijkstra(int start, long long* dp, long long* ways) {
  fill(dp, dp + N, inf);
  memset(ways, 0, sizeof(ways));
  dp[start] = 0;
  ways[start] = 1;
  priority_queue<pair<long long, int>> pq;
  pq.emplace(dp[start], start);
  while (!pq.empty()) {
    long long cost; int now;
    tie(cost, now) = pq.top();
    pq.pop();
    cost = -cost;
    if (cost != dp[now]) continue;
    for (auto it : edge[now]) {
      int near = it.first;
      long long ncos = cost + it.second;
      if (dp[near] > ncos) {
        dp[near] = ncos;
        ways[near] = ways[now];
        pq.emplace(-dp[near], near);
      } else if (dp[near] == ncos) {
        ways[near] = (ways[near] + ways[now]) % mod;
      }
    }
  }
}

int main() {
  int n, m, s, t;
  scanf("%d %d %d %d", &n, &m, &s, &t);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edge[u].emplace_back(v, w);
    edge[v].emplace_back(u, w);
  }
  dijkstra(s, d0, w0);
  dijkstra(t, d1, w1);
  long long distance = d0[t];
  //cout << distance << endl;
  long long ans = w0[t] * w1[s] % mod;
  //printf("%lld %lld\n", w0[t], w1[s]);
  for (int i = 1; i <= n; i++) {
    if (2 * d0[i] == distance) {
      //printf("titik %d\n", i);
      long long subs = w0[i] * w1[i] % mod;
      subs = subs * subs % mod;
      ans -= subs;
      ans %= mod;
      if (ans < 0) ans += mod;
    }
  }
  //for (int i = 1; i <= n; i++) printf("%lld ", w0[i]); printf("\n");
  //for (int i = 1; i <= n; i++) printf("%lld ", w1[i]); printf("\n");
  for (int i = 1; i <= n; i++) {
    for (auto it : edge[i]) {
      int to = it.first;
      if (d0[i] * 2 < distance && d0[to] > distance / 2 && d0[i] + it.second + d1[to] == distance) {
        //printf("%d %d\n", i, to);
        long long subs = w0[i] * w1[to] % mod;
        subs = subs * subs % mod;
        ans -= subs;
        ans %= mod;
        if (ans < 0) ans += mod;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
