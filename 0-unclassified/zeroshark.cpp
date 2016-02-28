#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 1e5 + 5;

long long dp[N][2][2];

int main() {
  dp[1][0][0] = 1;
  dp[1][1][0] = 1;
  for(int i = 2; i < N; i++) {
    dp[i][0][0] += dp[i - 1][1][0];
    
    dp[i][0][1] += dp[i - 1][0][0];
    dp[i][0][1] += dp[i - 1][1][1];
    
    dp[i][1][0] += dp[i - 1][0][0];
    dp[i][1][0] += dp[i - 1][1][0];
    
    dp[i][1][1] += dp[i - 1][0][1];
    dp[i][1][1] += dp[i - 1][1][1];
    
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < 2; k++) {
        dp[i][j][k] %= mod;
      }
    }
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", (int) ((dp[n][0][1] + dp[n][1][1]) % mod));
  }
  
  return 0;
}
