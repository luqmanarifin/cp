
#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int T = 5105;

int f[N], s[N];
double p[N];
int n, r;
double dp[N][T];

double solve(double x) {
  for (int j = 0; j < T; j++) {
    if (j <= r) {
      dp[n][j] = 0;
    } else {
      dp[n][j] = x;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < T; j++) dp[i][j] = x;
    for (int j = 0; j <= r; j++) {
      dp[i][j] = p[i] * (f[i] + min(x, dp[i+1][j + f[i]]))
               + (1 - p[i]) * (s[i] + min(x, dp[i+1][j + s[i]]));
    }
  }
  return dp[0][0];
}

int main() {
  scanf("%d %d", &n, &r);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %lf", f + i, s + i, p + i);
    p[i] /= 100;
  }
  double l = 0, r = 1e18;
  for (int iter = 0; iter < 150; iter++) {
    //printf("%.10f %.10f\n", l, r);
    double mid = (l + r) / 2;
    if (solve(mid) < mid) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.15f\n", r);
  return 0;
}
