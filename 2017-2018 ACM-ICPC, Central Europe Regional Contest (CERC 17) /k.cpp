#include <bits/stdc++.h>

using namespace std;

const int N = 555, inf = 1e8 + 7, M = 49 * 49 * 49;

int dp[N][M];

char s[N];

void upd(int & x, int y) {
  x = min(x, y);
}

int pw[7];

int main() {
  pw[0] = 1;
  for (int i = 0; i < 6; ++i)
    pw[i+1] = pw[i] * 7;
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j < M; ++j)
      dp[i][j] = inf;
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    char ma = 0;
    for (int j = 0; j < 7; ++j)
      ma = max(ma, s[j]);
    int mma = 0;
    for (int j = 0; j < 7; ++j)
      if (s[j] == ma)
        mma |= 1 << j;
    for (int j = 0; j < M; ++j) {
      int cost = 0;
      for (int k = 0, now = j; k < 6; ++k) {
        int c = now % 7;
        now /= 7;
        cost += c * (k+1);
        if (c < 6)
          upd(dp[i][j + pw[k]], dp[i][j]+1);
      }
      cost %= 7;
      if ((mma & (1 << cost)) == 0) {
        dp[i][j] = inf;
      }
    }
    for (int j = 0; j < M; ++j) {
      if (dp[i][j] == inf) continue;
      upd(dp[i+1][j], dp[i][j]);
    }
    for (int j = M-1; j >= 0; --j) {
      for (int k = 0, now = j; k < 6; ++k) {
        int c = now % 7;
        now /= 7;
        if (c > 0)
          upd(dp[i+1][j-pw[k]], dp[i+1][j]);
      }
    }
    //~ for (int j = 0; j < M; ++j) if (dp[i][j] != inf)
      //~ cerr << i << " " << j << " " << dp[i][j] << endl;
  }
  int ans = inf;
  for (int i = 0; i < M; ++i)
    ans = min(ans, dp[n-1][i]);
  printf("%d\n", ans);
  return 0;
}
