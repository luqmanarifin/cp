#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int C = 6;

int c[6][6] = {
  {0, 0, 1, 1, 1, 1},
  {0, 0, 1, 1, 1, 1},
  {1, 1, 0, 0, 1, 1},
  {1, 1, 0, 0, 1, 1},
  {1, 1, 1, 1, 0, 0},
  {1, 1, 1, 1, 0, 0}
};

long long dp[100][C];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < C; i++) dp[1][i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < C; j++) {
      for (int k = 0; k < C; k++) {
        if (c[j][k] == 0) continue;
        for (int l = 0; l < C; l++) {
          if (c[j][l] == 0) continue;
          dp[i][j] += dp[i-1][k] * dp[i-1][l] % mod;
          dp[i][j] %= mod;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < C; i++) ans = (ans + dp[n][i]) % mod;
  cout << ans << endl;
  return 0;
}
