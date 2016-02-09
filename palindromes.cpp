#include <bits/stdc++.h>

using namespace std;

char s[5005];
int dp[5005][5005];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for(int i = 1; i <= n; i++) {
    for(int j = 0; i - j >= 1 && i + j <= n; j++) {
      if(s[i - j] != s[i + j]) break;
      dp[i - j][i + j]++;
    }
  }
  for(int i = 1; i < n; i++) {
    for(int j = 0; i - j >= 1 && i + 1 + j <= n; j++) {
      if(s[i - j] != s[i + 1 + j]) break;
      dp[i - j][i + 1 + j]++;
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    }
  }
  int q;
  scanf("%d", &q);
  while(q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", dp[r][r] - dp[r][l - 1] - dp[l - 1][r] + dp[l - 1][l - 1]);
  }
  return 0;
}
