#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int mod = 1e9 + 7;

char a[N], b[N];
// pos - k - last- ngikut
int dp[N][N][2][2], k;

long long find(int n, char* s) {
  if (k == 0) return n;
  if (n == 1) return 0;
  memset(dp, 0, sizeof(dp));
  dp[2][1][0][s[1] == '0'] = 1;
  if (s[1] == '1') {
    dp[2][0][1][1] = 1;
  }
  for (int i = 1; i < n; i++) {
    if (i + 2 <= n) {
      dp[i + 2][1][0][0]++;
      dp[i + 2][0][1][0]++;
    }
    for (int j = 0; j <= k; j++) {
      dp[i+1][j+1][0][0] += dp[i][j][0][0];
      dp[i+1][j+1][0][0] %= mod;
      dp[i+1][j+1][0][0] += dp[i][j][1][0];
      dp[i+1][j+1][0][0] %= mod;
      dp[i+1][j][1][0] += dp[i][j][0][0];
      dp[i+1][j][1][0] %= mod;
      dp[i+1][j][1][0] += dp[i][j][1][0];
      dp[i+1][j][1][0] %= mod;
      
      if (s[i] == '0') {    // cuma bisa ngisi 0
        dp[i+1][j+1][0][1] += dp[i][j][0][1];
        dp[i+1][j+1][0][1] %= mod;
        dp[i+1][j+1][0][1] += dp[i][j][1][1];
        dp[i+1][j+1][0][1] %= mod;
      } else {              // bisa ngisi 0 dan 1
        dp[i+1][j+1][0][0] += dp[i][j][0][1];
        dp[i+1][j+1][0][0] %= mod;
        dp[i+1][j][1][1] += dp[i][j][0][1];
        dp[i+1][j][1][1] %= mod;
        dp[i+1][j+1][0][0] += dp[i][j][1][1];
        dp[i+1][j+1][0][0] %= mod;
        dp[i+1][j][1][1] += dp[i][j][1][1];
        dp[i+1][j][1][1] %= mod;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += (long long) dp[i][k-1][1][0] + dp[i][k-1][1][1];
  }
  return ans % mod;
}

int main() {
  scanf("%s %s %d", a, b, &k);
  long long ans = find(strlen(b), b);
  int lena = strlen(a);
  for (int i = lena - 1; i >= 0; i--) {
    if (a[i] == '1') {
      a[i] = '0';
      break;
    } else {
      a[i] = '1';
    }
  }
  if (lena == 1 && a[0] == '0') {
    
  } else {
    if (a[0] == '0') {
      ans -= find(lena - 1, a + 1);
    } else {
      ans -= find(lena, a);
    }
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}
