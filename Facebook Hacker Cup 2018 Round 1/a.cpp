#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const long long mod = 1e9 + 7;

long long dp[3][N];
char s[N][N];

void add(long long& at, long long val) {
  at += val;
  if (at >= mod) at -= mod;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 3; i++) scanf("%s", s[i] + 1);
    //for (int i = 0; i < 3; i++) printf("%s\n", s[i] + 1);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
      if (s[0][i] == '.' && s[1][i] == '.') {
        add(dp[1][i], dp[0][i-1]);
        add(dp[0][i], dp[1][i-1]);
      }
      if (s[1][i] == '.' && s[2][i] == '.') {
        add(dp[1][i], dp[2][i-1]);
        add(dp[2][i], dp[1][i-1]);
      }
    }
    printf("Case #%d: %lld\n", tt, dp[2][n]);
    fprintf(stderr, "%d done!\n", tt);
  }

  return 0;
}
