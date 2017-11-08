#include <bits/stdc++.h>

using namespace std;

const int N = 405;

double dp[N][N];
bool vis[N][N];
int n, k;

double dfs(int i, int j) {
  if (j == k) return i;
  if (vis[i][j]) return dp[i][j];
  vis[i][j] = 1;
  double best = -1;
  if (i > 0) {
    best = max(best, dfs(i, j + 1) / 2 + dfs(i - 1, j + 1) / 2);
  }
  if (i < n) {
    best = max(best, dfs(i, j + 1) / 2 + dfs(i + 1, j + 1) / 2);
  }
  return dp[i][j] = best;
}

int main() {
  scanf("%d %d", &n, &k);
  printf("%.15f\n", dfs(0, 0));
  return 0;
}
