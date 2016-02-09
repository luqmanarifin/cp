#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const long long inf = 1e18;

long long dp[N][N];
int a[N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
      scanf("%d", a + i);
    }
    sort(a + 1, a + 1 + n);
    for(int i = 0; i <= n; i++) {
      for(int j = 0; j <= m; j++) {
        dp[i][j] = inf;
      }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        for(int k = 1; k <= i; k++) {
          dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + a[i] - a[k]);
        }
      }
    }
    printf("Case #%d: %lld\n", tt, dp[n][m]);
  }
  
  return 0;
}
