#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-12;

double a[20][20];
double dp[18][1 << 18];
double m[18][1 << 18];

bool equal(double c, double d) {
  return abs(c - d) < eps;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%lf", &a[i][j]);
    }
  }
  int pol = (1 << n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      int must = (1 << i) | (1 << j);
      for(int mask = must; mask < pol; mask++, mask |= must) {
        m[j][mask] += a[i][j];
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < pol; j++) {
      int bit = __builtin_popcount(j);
      m[i][j] /= 1.0 * bit * (bit - 1) / 2;
    }
  }
  dp[0][(1 << n) - 1] = 1.0;
  for(int i = 0; i <= n - 2; i++) {
    for(int mask = 0; mask < pol; mask++) {
      if(equal(dp[i][mask], 0.0)) continue;
      for(int f = 0; f < n; f++) if(mask & (1 << f)) {
        dp[i + 1][mask ^ (1 << f)] += dp[i][mask] * m[f][mask];
      }      
    }
  }
  for(int i = 0; i < n; i++) printf("%.15lf ", dp[n - 1][1 << i]);
  printf("\n");
  return 0;
}