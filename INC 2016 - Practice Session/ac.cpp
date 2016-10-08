#include <bits/stdc++.h>

using namespace std;

const int N = 15, inf = 1e8;

int dp[1<<N];
int a[N][N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n;
    scanf("%d", &n);
    n *= 3;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        scanf("%d", a[i]+j);
    int m = 1<<n;
    for (int i = 0; i < m; i++) if((__builtin_popcount(i) % 3) == 0) {
      dp[i] = -1;
      for (int j = 0; j < n; j++) if ((i & (1<<j))) {
        for (int k = j+1; k < n; k++) if ((i & (1<<k)))
        for (int l = k+1; l < n; l++) if ((i & (1<<l))) {
          int mask = i ^ (1<<j) ^ (1<<k) ^ (1<<l);
          dp[i] = max(dp[i], min(dp[mask], a[j][k] + a[j][l] + a[k][l]));
        }
        break;
      }
      if (dp[i] == -1)
        dp[i] = inf;
      // cerr << i << " " << dp[i] << endl;
    }
    printf("Case #%d: %d\n", tc, dp[m-1]);
  }

  return 0;
}