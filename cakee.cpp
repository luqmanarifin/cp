#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int dp[N][N];
int n, m, k;
char s[N];

int solve(int i, int c) {
  if(1 <= c && c <= k) return 1;
  if(dp[i][c] != -1) return dp[i][c];
  int& ret = dp[i][c];
  bool all_lose = 1, all_win = 1;
  for(int it = k; it >= 1; it--) {
    if(solve(i + 1, c - it)) {
      all_lose = 0;
    } else {
      all_win = 0;
    }
    if(s[i + 1] == s[i] && !all_lose) {
      return ret = 1;
    }
    if(s[i + 1] != s[i] && !all_win) {
      return ret = 1;
    }
  }
  return ret = 0;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    scanf("%d %d %d %s", &n, &m, &k, s);
    for(int i = 0; i < 2 * n; i++) {
      for(int j = 0; j <= m; j++) {
        dp[i][j] = -1;
      }
      s[i] -= 'A';
    }
    int ans = (solve(0, m)? s[0] : (s[0] ^ 1));
    printf("Case #%d: %c\n", tt, ans + 'A');
  }
  
  return 0;
}
