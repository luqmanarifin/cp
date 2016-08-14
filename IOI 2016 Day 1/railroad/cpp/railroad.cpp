#include "railroad.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 16;
const long long inf = 1e18;

long long dp[N][1 << N];

long long plan_roller_coaster(std::vector<int> s, std::vector<int> t) {
  int n = s.size();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < (1 << N); j++) {
      dp[i][j] = inf;
    }
  }
  for (int i = 0; i < n; i++) {
    dp[i][1 << i] = 0;
  }
  for (int mask = 1; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if (dp[i][mask] == inf) continue;
      //if (dp[i][mask] == 0) printf("%d %d\n", i, mask);
      for (int j = 0; j < n; j++) {
        if ((mask & (1 << j)) == 0) {
          int cur = (mask | (1 << j));
          dp[j][cur] = min(dp[j][cur], dp[i][mask] + (t[i] > s[j]? t[i] - s[j] : 0));
        }
      }
    }
  }
  long long ans = inf;
  for (int i = 0; i < n; i++) ans = min(ans, dp[i][(1 << n) - 1]);
  return ans;
}
