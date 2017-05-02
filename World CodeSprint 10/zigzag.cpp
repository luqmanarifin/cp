#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int inf = 1e9;

// 0 standar, 1 naik, 2 turun
int dp[N][3], a[N];

void upd(int& at, int val) {
  at = min(at, val);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      dp[i][j] = inf;
    }
  }
  int ans = inf;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = i - 1;
    for (int j = 1; j < i; j++) {
      if (a[j] < a[i]) {
        for (int k = 0; k < 3; k++) {
          if (k == 1) continue;
          upd(dp[i][1], dp[j][k] + i - j - 1);
        }
      } else if (a[j] > a[i]) {
        for (int k = 0; k < 3; k++) {
          if (k == 2) continue;
          upd(dp[i][2], dp[j][k] + i - j - 1);
        }
      } else {
        for (int k = 0; k < 3; k++) {
          upd(dp[i][0], dp[j][k] + i - j - 1);
        }
      }
    }
    for (int j = 0; j < 3; j++) upd(ans, dp[i][j] + n - i);
  }
  cout << ans << endl;
  return 0;
}
