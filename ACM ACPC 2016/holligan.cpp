#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

char s[N][5];
int to[N];
int dp[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    fill(dp, dp + N, N);
    
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%s", s[i]);
    }
    for (int i = 1; i <= n; i++) {
      int j = i;
      while (j + 1 <= n && s[j][0] == s[j + 1][0] && s[j][1] == s[j + 1][1]) j++;
      for (int k = i; k <= j; k++) to[k] = j;
      i = j;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      dp[i] = min(dp[i], dp[i - 1] + 2 * (s[i][0] != s[i][1]));
      if (to[i] != i) {
        dp[to[i]] = min(dp[to[i]], dp[i - 1]);
      }
    }
    printf("%d\n", dp[n]);
  }

  return 0;
}
