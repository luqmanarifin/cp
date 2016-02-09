#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const int inf = 1e9;

vector<int> edge[N];
int n, f[N], dp[N][N];

void solve(int x, int p) {
  f[x] = (edge[x].size() == 1);
  for(auto it : edge[x]) {
    if(it == p) continue;
    solve(it, x);
    f[x] += f[it];
  }
  for(int i = 0; i <= n; i++) {
    dp[x][i] = inf;
  }
  dp[x][0] = 0;
  for(auto it : edge[x]) {
    if(it == p) continue;
    for(int j = f[x]; j >= 0; j--) {
      for(int k = 0; k <= min(f[it], j); k++) {
        dp[x][j] = min(dp[x][j], dp[it][k] + dp[x][j - k]);
      }
    }
  }
  for(int i = 0; i <= f[x]; i++) {
    dp[x][i] = min(dp[x][i], dp[x][f[x] - i] + 1);
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  int root = 1;
  while(edge[root].size() == 1) root++;
  solve(root, -1);
  printf("%d\n", n == 2? 1 : dp[root][f[root] / 2]);
  return 0;
}
