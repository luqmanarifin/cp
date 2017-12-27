#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 5005;

long long dp[N][N];
char s[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf(" %c", &s[i]);
  dp[0][0] = 1;
  for (int i = 0; i + 1 < n; i++) {
    for (int j = 0; j < N; j++) {
      if (s[i] == 'f' && j + 1 < N) {
        dp[i + 1][j + 1] += dp[i][j];
        dp[i + 1][j + 1] %= mod;
      }
      if (s[i] == 's') {
        dp[i + 1][j] += dp[i][j];
        dp[i + 1][j] %= mod;
      }
    }
    if (s[i] == 's') {
      for (int j = N - 2; j >= 0; j--) {
        dp[i + 1][j] += dp[i + 1][j + 1];
        dp[i + 1][j] %= mod;
      }
    }
  }
  long long ans = 0;
  for (int j = 0; j < N; j++) {
    ans += dp[n - 1][j];
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
