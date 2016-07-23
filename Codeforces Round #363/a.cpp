#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int inf = 1e9;

int dp[N][3];
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = 1;
  if (a[0] & 1) {
    dp[0][1] = 0;
  }
  if (a[0] & 2) {
    dp[0][2] = 0;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      if (j && (a[i] & j) == 0) continue;
      for (int k = 0; k < 3; k++) {
        if (j && j == k) continue;
        dp[i][j] = min(dp[i][j], dp[i - 1][k] + !j);
      }        
    }
  }
  int ans = inf;
  for (int j = 0; j < 3; j++) ans = min(ans, dp[n - 1][j]);
  cout << ans << endl;
  return 0;
}
