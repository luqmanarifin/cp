#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long dp[205][205][55];
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
    dp[0][m - k][k] = 1;
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j <= m - k; j++) {
        for(int c = 0; c <= k; c++) {
          dp[i][j][c] = dp[i - 1][j][c] + dp[i - 1][j + 1][c];
          if(a[i] >= d) {
            dp[i][j][c] += dp[i - 1][j][c + 1];
          } else {
            
          }
          dp[i][j][c] %= mod;
        }
      }
    }
    printf("%I64d\n", dp[n][0][0]);
  }
  return 0;
}