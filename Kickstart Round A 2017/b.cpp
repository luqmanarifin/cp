#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

vector<vector<bool>> dp[N][N];
char a[N], b[N];

int main() __attribute__((optimize("-O2")));
int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%s %s", a, b);
    int n = strlen(a);
    int m = strlen(b);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dp[i][j].clear();
      }
    }
    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= m + 1; j++) {
        int len = 1;
        if (a[i] == '*') len = 5;
        int lenb = 1;
        if (b[j] == '*') lenb = 5;
        
        dp[i][j].resize(len);
        for (int k = 0; k < len; k++) {
          dp[i][j][k].resize(lenb);
        }
      }
    }
    dp[0][0][0][0] = 1;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        int sa = dp[i][j].size();
        for (int k = 0; k < sa; k++) {
          int sb = dp[i][j][k].size();
          for (int l = 0; l < sb; l++) {
            //printf("%d %d %d %d\n", i, j, k, l);
            if (dp[i][j][k][l] == 0) continue;
            if (a[i] == '*' && b[j] == '*') {
              if (k + 1 < sa && l + 1 < sb) {
                dp[i][j][k+1][l+1] = 1;
              }
            }
            if (a[i] == '*') {
              dp[i+1][j][0][l] = 1;
              if (k + 1 < sa) {
                dp[i][j+1][k+1][0] = 1;
              }
            }
            if (b[j] == '*') {
              dp[i][j+1][k][0] = 1;
              if (l + 1 < sb) {
                dp[i+1][j][0][l+1] = 1;
              }
            }
            if (a[i] == b[j]) {
              dp[i+1][j+1][0][0] = 1;
            }
          }
        }
      }
    }
    bool ok = 0;
    for (int k = 0; k < dp[n][m].size(); k++) {
      for (int l = 0; l < dp[n][m][k].size(); l++) {
        ok |= dp[n][m][k][l];
      }
    }
    printf("Case #%d: %s\n", tt, ok? "TRUE" : "FALSE");
    cerr << tt << " done!" << endl;
  }
  
  return 0;
}
