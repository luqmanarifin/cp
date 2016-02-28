#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 55;

// problem - curang - time
int dp[N][N][N], tmp[N][N][N];
int c[N][3];
int a[N][3];
int cs[N][1 << 3];
int as[N][1 << 3];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, most, time;
    scanf("%d %d %d", &n, &most, &time);
    most = min(most, n);
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j < 3; j++) {
        scanf("%d", &c[i][j]);
      }
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j < 3; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    for(int i = 1; i <= n; i++) {
      for(int mask = 0; mask < (1 << 3); mask++) {
        cs[i][mask] = as[i][mask] = 0;
        for(int j = 0; j < 3; j++) {
          if(mask & (1 << j)) {
            cs[i][mask] += c[i][j];
            as[i][mask] += a[i][j];
          }
        }
      }
    }
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        for(int k = 0; k < N; k++) {
          dp[i][j][k] = -inf;
        }
      }
    }
    dp[0][0][0] = 0;
    for(int iter = 1; iter <= n; iter++) {
      for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
          for(int k = 0; k < N; k++) {
            tmp[i][j][k] = dp[i][j][k];
          }
        }
      }
      for(int mask = 1; mask < (1 << 3); mask++) {
        for(int i = 0; i <= n; i++) {
          for(int j = 0; j <= most; j++) {
            for(int k = 0; k <= time; k++) {
              int cnt = __builtin_popcount(mask);
              int it = i + cnt;
              int jt = j + cnt - 1;
              int kt = k + cs[iter][mask];
              if(it > n || jt > most || kt > time) continue;
              tmp[it][jt][kt] = max(tmp[it][jt][kt], dp[i][j][k] + as[iter][mask]);
            }
          }
        }
      }
      for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
          for(int k = 0; k < N; k++) {
            dp[i][j][k] = tmp[i][j][k];
          }
        }
      }
    }
    int ans = -inf;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        for(int k = 0; k < N; k++) {
          ans = max(ans, dp[i][j][k]);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
