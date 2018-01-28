#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

long long dp[N];
vector<pair<int, int>> edge[N];

bool dfs(int now, long long cost) {
  if (dp[now] != inf) return dp[now] == cost;
  dp[now] = cost;
  for (auto it : edge[now]) {
    if (dfs(it.first, cost + it.second) == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int l, r, d;
    scanf("%d %d %d", &l, &r, &d);
    edge[l].emplace_back(r, d);
    edge[r].emplace_back(l, -d);
  }
  fill(dp, dp + N, inf);
  for (int i = 1; i <= n; i++) {
    if (dp[i] == inf) {
      if (dfs(i, 0) == 0) {
        puts("No");
        return 0;
      }
    }
  }
  puts("Yes");
  return 0;
}
