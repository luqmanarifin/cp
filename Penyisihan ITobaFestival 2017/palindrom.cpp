#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int dp[N][N];
char s[N];

int dfs(int i, int j) {
  if (dp[i][j] != -1) return dp[i][j];
  if (i > j) return 0;
  if (i == j) return 1;
  int ret = dfs(i + 1, j);
  ret = max(ret, dfs(i, j - 1));
  if (s[i] == s[j]) ret = max(ret, dfs(i + 1, j - 1) + 2);
  return dp[i][j] = ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(dp, -1, sizeof(dp));
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    printf("%d\n", dfs(1, n)); 
  }
  return 0;
}
