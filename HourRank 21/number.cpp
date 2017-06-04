#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 9;

int dp[N][15];

int main() {
  int s, m, d;
  scanf("%d %d %d", &s, &m, &d);
  for (int i = 1; i <= m; i++) dp[i][i] = 1;
  for (int i = 1; i <= s; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = max(1, j - d); k <= min(m, j + d); k++) {
        if (i - j >= 0) {
          dp[i][j] += dp[i - j][k];
          dp[i][j] %= mod;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= m; i++) ans += dp[s][i];
  cout << ans % mod << endl;
  return 0;
}
