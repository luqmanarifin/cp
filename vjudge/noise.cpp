#include <bits/stdc++.h>

using namespace std;

const int N = 105;

long long dp[N][2];

int main() {
  dp[1][0] = dp[1][1] = 1;
  for (int i = 2; i <= 50; i++) {
    dp[i][0] = dp[i-1][0] + dp[i-1][1];
    dp[i][1] = dp[i-1][0];
  }
  
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    printf("Scenario #%d:\n%lld\n\n", tt, dp[n][0] + dp[n][1]);
  }
  return 0;
}
