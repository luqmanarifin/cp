#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const int N = 1005;

long long dp[N][2];
char s[N];

void upd(long long& at, long long val) {
  at = min(at, val);
}


int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int x, y;
    scanf("%d %d %s", &x, &y, s);
    int n = strlen(s);

    for (int i = 0; i < N; i++) dp[i][0] = dp[i][1] = inf;
    if (s[0] == 'C') {
      dp[0][0] = 0;
    } else if (s[0] == 'J') {
      dp[0][1] = 0;
    } else {
      dp[0][0] = 0;
      dp[0][1] = 0;
    }

    for (int i = 1; i < n; i++) {
      // can C
      if (s[i] == 'C' || s[i] == '?') {
        upd(dp[i][0], dp[i-1][0]);
        upd(dp[i][0], dp[i-1][1] + y);
      }
      // can J
      if (s[i] == 'J' || s[i] == '?') {
        upd(dp[i][1], dp[i-1][1]);
        upd(dp[i][1], dp[i-1][0] + x);
      }
    }
    printf("Case #%d: %lld\n", tt, min(dp[n-1][0], dp[n-1][1]));
  }

  return 0;
}
