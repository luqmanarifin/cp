#include "tour.h"
#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

const int N = 305;

int dp[1 << 16], tmp[1 << 16];

void upd(int& at, int val) {
  at = max(at, val);
}

int getShortestTour(int n, std::vector<std::string> s) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    memset(tmp, 0, sizeof(tmp));
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int j = 0; j < n; j++) {
        if ((mask & (1 << j)) == 0 && s[i][j] == '.') {
          upd(tmp[mask | (1 << j)], dp[mask] + 1);
        }
      }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
      upd(dp[mask], tmp[mask]);
    }
  }
  for (int mask = 0; mask < (1 << n); mask++) upd(ans, dp[mask]);
  
  ans = min(ans, n - 1);
  return 2 * (n - 1) - ans;
}
