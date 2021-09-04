#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const int N = 1e5 + 5;

long long dp[N][10][2];   // pos - last digit - use
int f[10][10];
char s[N];

void upd(long long& at, long long val) {
  at = max(at, val);
}

int main() {
  int n, k;
  scanf("%d %d %s", &n, &k, s);
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      scanf("%d", &f[i][j]);
    }
  }
  for (int i = 0; i < n; i++) s[i] -= '0';
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      dp[i][j][0] = dp[i][j][1] = -inf;
    }
  }
  dp[0][s[0]][1] = 0;
  for (int i = 1; i < n; i++) {
    // not use now
    if (i < n - 1) {
      for (int j = 1; j <= k; j++) {
        for (int t = 0; t < 2; t++) {
          upd(dp[i][j][0], dp[i-1][j][t] + f[s[i-1]][s[i]]);
        }
      }
    } 
    // use now
    for (int j = 1; j <= k; j++) {
      upd(dp[i][s[i]][1], dp[i-1][j][0] + f[s[i-1]][s[i]] - f[j][s[i]]);
      upd(dp[i][s[i]][1], dp[i-1][j][1]);
    }
  }
  long long ans = 0;
  for (int j = 1; j <= k; j++) {
    upd(ans, dp[n-1][j][0]);
    upd(ans, dp[n-1][j][1]);
  }
  printf("%lld\n", ans);
  return 0;
}
