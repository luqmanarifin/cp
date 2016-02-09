#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int x[N], w[N];
int now[N];
int dp[N][3];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", x + i, w + i);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 3; j++) {
      dp[i][0] = max(dp[i][0], dp[i - 1][j]);
    }
    if(i == 1) {
      dp[i][1] = 1;
    } else {
      if(x[i - 1] < x[i] - w[i]) {
        dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
        dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
      }
      if(x[i - 1] + w[i - 1] < x[i] - w[i]) {
        dp[i][1] = max(dp[i][1], dp[i - 1][2] + 1);
      }
    }
    if(i == n || (i + 1 <= n && x[i] + w[i] < x[i + 1])) {
      for(int j = 0; j < 3; j++) {
        dp[i][2] = max(dp[i][2], dp[i - 1][j] + 1);
      }
    }
    
    for(int j = 0; j < 3; j++) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}
