#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 505;

int dp[105][2 * N];
int t[105], w[105];

int main() {
  for(int i = 0; i < 105; i++) {
    for(int j = 0; j < 2 * N; j++) {
      dp[i][j] = inf;
    }
  }
  int n, sum = 0;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", t + i, w + i);
    sum += w[i];
  }
  dp[0][0] = sum;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 2 * N; j++) {
      dp[i][j] = dp[i - 1][j];
    }
    for(int j = 0; j < N; j++) {
      dp[i][j + t[i]] = min(dp[i][j + t[i]], dp[i - 1][j] - w[i]);
    }
  }
  for(int j = 0; j <= sum; j++) {
    if(dp[n][j] <= j) {
      printf("%d\n", j);
      return 0;
    }
  }
  puts("ASU");
  return 0;
}
