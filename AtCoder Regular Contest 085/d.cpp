#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const long long inf = 1e18;

int a[N][2], n;
long long dp[N][N][2][2]; // pertama, kedua

long long dfs(int i, int j, int p, int move) {
  if (dp[i][j][p][move] != -1) return dp[i][j][p][move];
  if (i == n || j == n) return abs(a[i][0] - a[j][1]);
  long long& ret = dp[i][j][p][move];
  int pol = max(i, j);
  if (p == 0) {
    ret = dfs(pol + 1, j, p, 1);
    if (move) ret = max(ret, dfs(i, j, p ^ 1, 0));
  } else {
    ret = dfs(i, pol + 1, p, 1);
    if (move) ret = min(ret, dfs(i, j, p ^ 1, 0));
  }
  return ret;
  
}

int main() {
  scanf("%d %d %d", &n, &a[0][0], &a[0][1]);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i][0]), a[i][1] = a[i][0];
  memset(dp, -1, sizeof(dp));
  cout << dfs(0, 0, 0, 0) << endl;
  return 0;
}
