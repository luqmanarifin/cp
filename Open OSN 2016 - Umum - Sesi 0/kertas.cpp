#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int dp[N][N];

int dfs(int a, int b) {
  if(dp[a][b] != -1) return dp[a][b];
  for(int i = 1; i < a; i++) {
    if(dfs(i, b) == 0) return dp[a][b] = 1;
  }
  for(int i = 1; i < b; i++) {
    if(dfs(a, i) == 0) return dp[a][b] = 1;
  }
  return dp[a][b] = 0;
}

int main() {
  memset(dp, -1, sizeof(dp));
  dp[1][1] = 0;
  for(int i = 1; i < N; i++) {
    for(int j = 1; j < N; j++) {
      if(dfs(i, j) == 0) {
        printf("%d %d\n", i, j);
      }
    }
  }
  return 0;
}