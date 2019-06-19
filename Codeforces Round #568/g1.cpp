#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int dp[230][1 << 15][4];

void add(int& at, int val) {
  at += val;
  if (at >= mod) at -= mod;
}

int need[20], g[20];

int main() {
  int n, tot;
  scanf("%d %d", &n, &tot);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", need + i, g + i);
  }
  dp[0][0][0] = 1;
  for (int t = 0; t <= tot; t++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) continue;
        if (t + need[i] > tot) continue;
        for (int k = 0; k < 4; k++) {
          if (k == g[i]) continue;
          add(dp[t+need[i]][mask | (1 << i)][g[i]], dp[t][mask][k]);
        }
      }
    }
  }
  // cout << dp[1][1][1] << endl;
  int ans = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int k = 0; k < 4; k++) {
      add(ans, dp[tot][mask][k]);
    }
  }
  cout << ans << endl;
  return 0;
}
