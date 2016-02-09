#include <bits/stdc++.h>

using namespace std;

const double inf = 1e18;
const int N = 1300;
const double eps = 1e-11;

double dp[N][2], tmp[N][2];
int c[N], w[N];

bool eq(double a, double b) {
  return abs(a - b) < eps;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
      scanf("%d", c + i);
    }
    for(int i = 0; i < n; i++) {
      scanf("%d", w + i);
    }
    for(int i = 0; i <= m; i++) {
      dp[i][0] = inf;
      dp[i][1] = -inf;
    }
    dp[0][0] = dp[0][1] = 15000;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j <= m; j++) {
        tmp[j][0] = inf;
        tmp[j][1] = -inf;
      }
      for(int j = 0; j <= m; j++) {
        for(int k = 0; k < 2; k++) {
          if(eq(inf, abs(dp[j][k]))) continue;
          double good = (dp[j][k] * (100 - w[i]) + -dp[j][k] * w[i]) / 100;
          double bad = (dp[j][k] * c[i] + -dp[j][k] * (100 - c[i])) / 100;
          tmp[j][0] = min(tmp[j][0], good);
          tmp[j][1] = max(tmp[j][1], good);
          tmp[j + 1][0] = min(tmp[j + 1][0], bad);
          tmp[j + 1][1] = max(tmp[j + 1][1], bad);
        }
      }
      for(int j = 0; j <= m; j++) {
        dp[j][0] = tmp[j][0];
        dp[j][1] = tmp[j][1];
      }
    }
    double ans = inf;
    for(int j = 0; j <= m; j++) {
      ans = min(ans, dp[j][0]);
    }
    printf("Case #%d: %.3f\n", tt, ans);
  }
  
  return 0;
}
