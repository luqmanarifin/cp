#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const long long inf = 1e18;

long long dp[N][N];

void upd(long long& a, long long b) {
  a = max(a, b);
}

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = -inf;
    }
  }  

  int n, c, x1, u, x2;
  scanf("%d %d %d %d %d", &n, &c, &x1, &u, &x2);
  dp[0][0] = c;
  for (int i = 0; i < n; i++) {
    for (int j = N - 2; j >= 0; j--) {
      if (dp[i][j] >= u) {
        upd(dp[i][j + 1], dp[i][j] - u);
      }
    }
    for (int j = 0; j < N; j++) {
      upd(dp[i+1][j], dp[i][j] + x1 + j * x2);
    }
  }
  long long ans = -inf;
  for (int j = 0; j < N; j++) {
    //if (dp[n][j] >= 0) printf("%d %d: %lld\n", n, j, dp[n][j]);
    ans = max(ans, dp[n][j]);
  }
  cout << ans << endl;
  //cout << dp[1][0] << endl;
  return 0;
}
