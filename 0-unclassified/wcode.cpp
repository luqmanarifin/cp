#include <bits/stdc++.h>

using namespace std;

const int N = 505;

long long mod;

void norm(long long &cuk) {
  cuk %= mod;
}

long long dp[2][N][N];
int a[N];

int main() {
  int n, m, b;
  scanf("%d %d %d %I64d", &n, &m, &b, &mod);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  
  dp[0][0][0] = 1;
  for(int it = 1; it <= n; it++) {
    int i = it % 2;
    for(int j = 0; j <= m; j++) {
      for(int k = 0; k <= b; k++) {
        dp[i][j][k] = dp[i ^ 1][j][k];
        if(j > 0 && k >= a[it]) {
          dp[i][j][k] += dp[i][j - 1][k - a[it]];
        }
        norm(dp[i][j][k]);
      }
    }
  }
  long long ans = 0;
  for(int bug = 0; bug <= b; bug++) {
    ans += dp[n % 2][m][bug];
  }
  norm(ans);
  cout << ans << endl;
  return 0;
}
