#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long dp[205][205][205];
int a[205];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(dp, 0, sizeof(dp));
    
    int n, m, k, d;
    scanf("%d %d %d %d", &n, &m, &k, &d);
    for(int i = 1; i <= n; i++) {
      scanf("%d", a + i);
    }
    k = min(k, m);
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j <= m; j++) {
        for(int c = 0; c <= m; c++) {
          dp[i][j][c] = dp[i - 1][j][c];
          if(j && a[i] < d) {
            dp[i][j][c] += dp[i - 1][j - 1][c];
          }
          if(c && a[i] >= d) {
            dp[i][j][c] += dp[i - 1][j][c - 1];
          }
          dp[i][j][c] %= mod;
        }
      }
    }
    long long ans = 0;
    for(int j = 0; j <= m; j++) {
      for(int c = 0; c <= m; c++) {
        if(j + c == m && c >= k) {
          ans += dp[n][j][c];
        }
      }
    }
    printf("%I64d\n", ans % mod);
  }
  return 0;
}