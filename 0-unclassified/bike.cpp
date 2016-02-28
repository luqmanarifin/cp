#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int p[] = {0, 4, 8, 11};

// index - ganti gigi - energy battery - last gigi
int dp[1005][12][52][5];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, c, e;
    scanf("%d %d %d", &n, &c, &e);
    for(int i = 0; i < 1005; i++) {
      for(int j = 0; j < 12; j++) {
        for(int k = 0; k < 52; k++) {
          for(int l = 0; l < 5; l++) {
            dp[i][j][k][l] = inf;
          }
        }
      }      
    }
    dp[0][c][e][0] = 0;
    for(int i = 1; i <= n; i++) {
      int a;
      scanf("%d", &a);
      for(int j = 0; j <= c; j++) {
        for(int k = 0; k <= e; k++) {
          for(int l = 0; l < 4; l++) {
            if(k + l > e) continue;
            int v = dp[i][j][k][l];
            for(int m = 0; m < 4; m++) {
              if(l == m) {
                v = min(v, dp[i - 1][j][k + l][m] + max(0, a - p[l]));
              } else {
                if(j + 1 <= c)
                v = min(v, dp[i - 1][j + 1][k + l][m] + max(0, a - p[l]));
              }
            }
            dp[i][j][k][l] = v;
          }
        }
      }
      int sud = inf;
      for(int j = 0; j <= c; j++) {
        for(int k = 0; k <= e; k++) {
          for(int l = 0; l < 4; l++) {
            sud = min(sud, dp[i - 1][j][k][l]);
          }
        }
      }
      dp[i][0][0][0] = min(dp[i][0][0][0], sud + a);
      /*
      if(i == 1) {
        for(int j = 0; j <= c; j++) {
          for(int k = 0; k <= e; k++) {
            for(int l = 0; l < 4; l++) {
              if(dp[i][j][k][l] != inf)
              printf("%d %d %d %d\n", j, k, l, dp[i][j][k][l]);
            }
          }
        }
      }
      */
    }
    int ans = inf;
    for(int j = 0; j <= c; j++) {
      for(int k = 0; k <= e; k++) {
        for(int l = 0; l < 4; l++) {
          ans = min(ans, dp[n][j][k][l]);
        }
      }
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
