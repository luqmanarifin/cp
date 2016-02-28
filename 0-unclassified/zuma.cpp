// too easy to AC
#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int dp[N][N], a[N];

int dfs(int l, int r) {
  if(dp[l][r] != -1) return dp[l][r];
  if(l > r) return 1;
  int& ret = dp[l][r] = (a[l] == a[r]? dfs(l + 1, r - 1) : N);
  for(int i = l; i < r; i++) {
    ret = min(ret, dfs(l, i) + dfs(i + 1, r));
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  memset(dp, -1, sizeof(dp));
  cout << dfs(0, n - 1) << endl;
  return 0;
}
