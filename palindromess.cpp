#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int mod = 1e9 + 7;

// bef/now - row depan - row belakang
long long dp[2][N][N];
char s[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  if(s[1][1] == s[n][m]) {
    dp[0][1][n] = 1;
  }
  int pol = (n + m - 2) / 2;
  for(int st = 1; st <= pol; st++) {
    for(int i = 1; i <= n; i++) {
      for(int k = 1; k <= n; k++) {
        int t = st % 2;
        dp[t][i][k] = 0;
        int j = st + 2 - i;
        int l = m - st + n - k;
        if(j < 1 || m < j || l < 1 || m < l) {
          continue;
        }
        if(s[i][j] == s[k][l]) {
          dp[t][i][k] = (dp[1 - t][i][k] + dp[1 - t][i - 1][k] + dp[1 - t][i][k + 1] + dp[1 - t][i - 1][k + 1]) % mod;
        }
      }
    }
  }
  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    if((n + m) % 2) {
      ans += dp[pol % 2][i][i] + dp[pol % 2][i][i + 1];
    } else {
      ans += dp[pol % 2][i][i];
    }
  }
  cout << ans % mod << endl;
  return 0;
}
