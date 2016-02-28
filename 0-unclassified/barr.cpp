#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int dp[31][31][55];

int find(int n, int m, int k) {
  if(dp[n][m][k] != -1) return dp[n][m][k];
  if(n * m == k || k == 0) return 0;
  int& ret = dp[n][m][k] = inf;
  for(int i = 1; i <= n / 2; i++) {
    for(int j = 0; j <= k; j++) {
      if(j > i * m || k - j > (n - i) * m) continue;
      ret = min(ret, find(i, m, j) + find(n - i, m, k - j) + m * m);
    }
  }
  for(int i = 1; i <= m / 2; i++) {
    for(int j = 0; j <= k; j++) {
      if(j > i * n || k - j > (m - i) * n) continue;
      ret = min(ret, find(n, i, j) + find(n, m - i, k - j) + n * n);
    }
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  memset(dp, -1, sizeof(dp));
  while(t--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    printf("%d\n", find(n, m, k));
  }
  
  return 0;
}
