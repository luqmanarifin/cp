
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int dp[N][N][2][26];
vector<pair<int, int>> edge[N];

int dfs(int a, int b, int turn, int last) {
  if (dp[a][b][turn][last] != -1) return dp[a][b][turn][last];
  set<int> s;
  if (turn == 0) {
    for (auto it : edge[a]) {
      if (it.second >= last) {
        s.insert(dfs(it.first, b, turn ^ 1, it.second));
      }
    }
  } else {
    for (auto it : edge[b]) {
      if (it.second >= last) {
        s.insert(dfs(a, it.first, turn ^ 1, it.second));
      }
    }
  }
  for (int i = 0; ; i++) {
    if (!s.count(i)) {
      return dp[a][b][turn][last] = i;
    }
  }
}

int main() {
  memset(dp, -1, sizeof(dp));
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    char c;
    scanf("%d %d %c", &u, &v, &c);
    edge[u].emplace_back(v, c - 'a');
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int ret = dfs(i, j, 0, 0);
      if (ret) {
        printf("A");
      } else {
        printf("B");
      }
    }
    printf("\n");
  }
  
  return 0;
}
