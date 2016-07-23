#include <bits/stdc++.h>

using namespace std;

const int N = 4;

long double dp[N][25];
int n, k;

double solve(double v) {
  memset(dp, 0, sizeof(dp));
  dp[0][n - 1] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][0] += v * dp[i - 1][j];
      int to = max(j + 1, n);
      dp[i][to] += (1 - v) * dp[i - 1][j];
    }
  }
  long double ans = 0;
  for (int j = 0; j < k; j++) {
    ans += dp[N - 1][j];
  }
  return (double) ans;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    double val;
    scanf("%lf", &val);
    printf("%.15f\n", solve(val));
  }
  
  return 0;
}
