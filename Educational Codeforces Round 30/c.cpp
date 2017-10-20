#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int BIG = 10005;
const int inf = 1e9;

int a[N][N];

int dp[BIG], bef[BIG], s[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  fill(dp, dp + BIG, inf);
  dp[0] = 0;
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i < N; i++) {
      s[i] = s[i - 1] + a[i][j];
    }
    for (int i = 0; i < BIG; i++) bef[i] = dp[i];
    int rem = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i][j] == 0) continue;
      int got = s[i + k - 1] - s[i - 1];
      //printf("dapet %d remove %d\n", got, rem);
      for (int l = 0; l + got < BIG; l++) {
        dp[l + got] = min(dp[l + got], bef[l] + rem);
      }
      //for (int l = 0; l < N * N; l++) if (dp[l] != inf) printf("%d %d\n", l, dp[l]);
      rem += a[i][j];
    }
  }
  for (int i = BIG - 1; i >= 0; i--) {
    if (dp[i] != inf) {
      printf("%d %d\n", i, dp[i]);
      return 0;
    }
  }
  assert(0);
  return 0;
}
