#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

double dp[N];

int main() {
  int n;
  double p;
  scanf("%d %lf", &n, &p);
  dp[0] = 1.0;
  for(int i = 0; i <= n; i++) {
    dp[i + 2] += dp[i] * p / 100;
    dp[i + 3] += dp[i] * (1 - p / 100);
  }
  printf("%.6lf\n", dp[n]);
  return 0;
}
