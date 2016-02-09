#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int mod = 1000007;

int dp[N][N * N / 2];

int main() {
  dp[1][0] = 1;
  for(int i = 2; i <= 200; i++) {
    dp[i][0] = 1;
    for(int j = 1; j <= i * (i - 1) / 2; j++) {
      dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
      if(dp[i][j] >= mod) {
        dp[i][j] -= mod;
      }
    }
    for(int j = i * (i - 1) / 2; j >= 0; j--) {
      if(j - i >= 0) {
        dp[i][j] -= dp[i][j - i];
      }
      if(dp[i][j] < 0) {
        dp[i][j] += mod;
      }
    }
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", dp[n][k]);
  }
  /*
  for(int i = 1; i <= 5; i++) {
    for(int j = 0; j <= i * (i - 1) / 2; j++) {
      printf("%d ", dp[i][j]);
    }
    printf("\n");
  }
  */
  return 0;
}
