#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int inf = 1e9;

int n, m;
int dp[N][N], a[N], b[N];

int solve(int i, int j) {
  if(i == n && j == m) return 0;
  if(i == n) return -inf;
  if(dp[i][j] != -1) return dp[i][j];
  int& ret = dp[i][j] = -inf;
  if(i < n) {
    ret = max(ret, solve(i + 1, j));
    if(j < m) {
      int cur = solve(i + 1, j + 1) + a[i] * b[j];
      if(cur > ret) {
        ret = cur;
        //printf("ketambahan %d %d %d\n", i, j, a[i] * b[j]);
      }
    }
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    scanf("%d %d", &n, &m);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for(int i = 0; i < m; i++) {
      scanf("%d", b + i);
    }
    printf("Case #%d: %d\n", tt, solve(0, 0));
  }
  
  return 0;
}
