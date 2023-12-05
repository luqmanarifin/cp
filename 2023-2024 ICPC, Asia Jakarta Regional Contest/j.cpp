#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 998244353, N = 5050;
 
long long dp[N][N][2], pw2[N];
 
void add(long long & var, long long x) {
  var += x;
  if (var >= mod)
    var -= mod;
}
 
int main() {
  pw2[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw2[i] = pw2[i-1] * 2 % mod;
  }
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  dp[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (j + 1 < n && a[j+1] > a[j]) {
        add(dp[i][j+1][1], dp[i][j][1] * pw2[j - i] % mod);
      }
      if (j + 1 < n) {
        add(dp[i][j+1][1], dp[i][j][0] * pw2[j - i] % mod);
      }
      if (i + 1 < n) {
        add(dp[i+1][j][0], dp[i][j][0]);
        add(dp[i+1][j][0], dp[i][j][1]);
      }
    }
  }
  long long ans = (dp[n-1][n-1][0] + dp[n-1][n-1][1]) % mod;
  if (ans < 0)
    ans += mod;
  cout << ans << endl;
  return 0;
}