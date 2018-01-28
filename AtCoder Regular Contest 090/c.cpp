#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[3][N], dp[3][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = max(dp[i][j], dp[i][j-1] + a[i][j]);
      dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i][j]);
      //printf("%d ", dp[i][j]);
    }
    //printf("\n");
  }
  cout << dp[2][n] << endl;
  return 0;
}
