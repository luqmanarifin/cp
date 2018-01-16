#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const int inf = 1e9;

int dp[N][N][2];
char s[N], t[N];

void mn(int& a, int b) {
  a = min(a, b);
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d %d %s %s", &n, &m, s + 1, t + 1);
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        dp[i][j][0] = dp[i][j][1] = inf;
      }
    }
    dp[1][0][0] = dp[0][1][1] = 1;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (i + 1 <= n) {
          if (i) mn(dp[i + 1][j][0], dp[i][j][0] + (s[i] != s[i + 1]));
          if (j) mn(dp[i + 1][j][0], dp[i][j][1] + (t[j] != s[i + 1]));
        }
        if (j + 1 <= m) {
          if (i) mn(dp[i][j + 1][1], dp[i][j][0] + (s[i] != t[j + 1]));
          if (j) mn(dp[i][j + 1][1], dp[i][j][1] + (t[j] != t[j + 1]));
        }
      }
    }
    printf("%d\n", min(dp[n][m][0], dp[n][m][1]));
  }

  return 0;
}
