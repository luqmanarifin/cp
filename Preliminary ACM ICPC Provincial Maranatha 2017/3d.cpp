#include <bits/stdc++.h>

using namespace std;

const int N = 15;

long long dp[N][N][N];

int main() {
  dp[0][0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (i) {
          dp[i][j][k] += dp[i-1][j][k];
        }
        if (j) {
          dp[i][j][k] += dp[i][j-1][k];
        }
        if (k) {
          dp[i][j][k] += dp[i][j][k-1];
        }
        //printf("%d %d %d: %lld\n", i, j, k, dp[i][j][k]);
        assert(dp[i][j][k] >= 0);
      }
    }
  }
  int a, b, c;
  while (scanf("%d %d %d", &a, &b, &c) != -1) {
    cout << dp[a][b][c] << endl;
  }

  return 0;
}
