#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char s[N];
int dp[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(dp, 0, sizeof(dp));
    
    int k;
    scanf("%s %d", s, &k);
    int n = strlen(s), used = 0, ans = 0;
    for (int i = 0; i <= n - k; i++) {
      if (i > 0) dp[i] += dp[i - 1];
      int now = ((s[i] == '-') + dp[i] - (i - k >= 0? dp[i-k] : 0)) % 2;
      if (now) {
        dp[i]++;
        ans++;
      }
    }
    bool possible = 1;
    for (int i = n - k + 1; i < n; i++) {
      if (i > 0) dp[i] += dp[i - 1];
      int now = ((s[i] == '-') + dp[i] - (i - k >= 0? dp[i-k] : 0)) % 2;
      if (now == 1) {
        possible = 0;
        break;
      }
    }
    printf("Case #%d: ", tt);
    if (!possible) {
      puts("IMPOSSIBLE");
    } else {
      printf("%d\n", ans);
    }
    cerr << tt << " done!" << endl;
  }

  return 0;
}
