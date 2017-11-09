#include <bits/stdc++.h>

using namespace std;

const int N = 1024, inf = 1e9 + 7;

int dp[N][N][2], p[N];

void upd(int &le, int ri) {
  le = max(le, ri);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", p+i);
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= k; j++)
        dp[i][j][0]  = dp[i][j][1] = -inf;
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= k; j++) {
        if (dp[i][j][0] > -inf) {
          upd(dp[i+1][j][0], dp[i][j][0]);
          upd(dp[i+1][j+1][1], dp[i][j][0] - p[i]);
        }
        if (dp[i][j][1] > -inf) {
          upd(dp[i+1][j][1], dp[i][j][1]);
          upd(dp[i+1][j][0], dp[i][j][1] + p[i]);
        }
      }
    }
    printf("%lld\n", 1LL * dp[n][k][0] * 1000);
  }
  return 0;
}
