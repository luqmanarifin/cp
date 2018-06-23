#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[2][N];

int mp[N];
int dp[N][1 << 2];

#define BOTH 3
#define ATAS 1
#define BAWA 2

void upd(int& at, int val) {
  at = max(at, val);
}

int main() {
  scanf("%s %s", s[0], s[1]);
  int n = strlen(s[0]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      if (s[j][i] == 'X') {
        mp[i] |= (1 << j);
      }
    }
  }
  for (int i = 0; i + 1 < n; i++) {
    for (int mask = 0; mask < (1 << 2); mask++) {
      int act = (mask | mp[i]);

      // trans 0
      if ((act & BOTH) == 0 && (mp[i + 1] & ATAS) == 0) {
        upd(dp[i + 1][ATAS], dp[i][mask] + 1);
      }

      // trans 1
      if ((act & ATAS) == 0 && (mp[i + 1] & BOTH) == 0) {
        upd(dp[i + 1][BOTH], dp[i][mask] + 1);
      }

      // trans 2
      if ((act & BAWA) == 0 && (mp[i + 1] & BOTH) == 0) {
        upd(dp[i + 1][BOTH], dp[i][mask] + 1);
      }

      // trans 3
      if ((act & BOTH) == 0 && (mp[i + 1] & BAWA) == 0) {
        upd(dp[i + 1][BAWA], dp[i][mask] + 1);
      }

      // ga diisi apapun
      upd(dp[i + 1][0], dp[i][mask]);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << 2); j++) {
      upd(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}
