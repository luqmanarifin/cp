#include <bits/stdc++.h>

using namespace std;

const int N = 400;

int n, k;
int dp[N];

int dfs(int w) {
  if(w <= 0) return 0;
  if(dp[w] != -1) return dp[w];
  return dp[w] = 1 + dfs(w - 1) + dfs(w - 1 - k);
}

int main() {
  scanf("%d %d", &k, &n);
  int w = 1;
  while((1 << w) - 1 < n) w++;
  memset(dp, -1, sizeof(dp));
  while(dfs(w + 1) <= n) w++;
  printf("%d\n", w);
  return 0;
}
