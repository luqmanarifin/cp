
#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int a[15][15][15];
int dp[15][15][15];

int main() {
  freopen("commandos.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(a, 0, sizeof(a));
    
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      int u, v, w, h;
      scanf("%d %d %d %d", &u, &v, &w, &h);
      a[u][v][w] += h;
    }    
    int s = 10;
    for (int i = 0; i < 15; i++) {
      for (int j = 0; j < 15; j++) {
        for (int k = 0; k < 15; k++) {
          dp[i][j][k] = -inf;
        }
      }
    }
    dp[10][1][1] = 0;
    for (int i = s; i >= 1; i--) {
      for (int j = 1; j <= s; j++) {
        for (int k = 1; k <= s; k++) {
          dp[i][j][k] = max(max(dp[i][j][k], dp[i + 1][j][k]), max(dp[i][j - 1][k], dp[i][j][k - 1]));
          dp[i][j][k] += a[i][j][k];
          //printf("%d ", dp[i][j][k]);
        }
        //printf("\n");
      }
      //printf("\n");
    }
    printf("%d\n", dp[1][s][s]);
  }

  return 0;
}
