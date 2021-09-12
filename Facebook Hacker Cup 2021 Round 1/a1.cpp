#include <bits/stdc++.h>

using namespace std;

const int N = 8e5 + 5;
const int inf = 1e9;

// 0 kiri, 1 kanan
int dp[N][2];
char s[N];

void upd(int& at, int val) {
  at = min(at, val);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < N; i++) {
      dp[i][0] = dp[i][1] = inf;
    }

    int n;
    scanf("%d %s", &n, s + 1);
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == 'F' || s[i] == 'X') {
        upd(dp[i][0], dp[i-1][1] + 1);
        upd(dp[i][0], dp[i-1][0]);
      }
      if (s[i] == 'F' || s[i] == 'O') {
        upd(dp[i][1], dp[i-1][0] + 1);
        upd(dp[i][1], dp[i-1][1]);
      }
    }
    printf("Case #%d: %d\n", tt, min(dp[n][0], dp[n][1]));
  }

  return 0;
}
