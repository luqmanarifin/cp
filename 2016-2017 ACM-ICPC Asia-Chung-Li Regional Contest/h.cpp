#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 5;
vector<int> g[N];

int dp[22][1 << 11];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
      g[i].clear();
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int p = n / 2;
    for (int i = 0; i <= p; i++) {
      for (int j = 0; j < (1 << p); j++)
        dp[i][j] = 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i < p; i++) {
      for (int j = 0; j < (1 << p); j++) {
        if (dp[i][j] == 0) continue;
        for (int u : g[i]) {
          if (!(u >= p && u < n)) continue;
          u -= p;
          if (j & (1 << u)) continue;
          dp[i+1][j | (1 << u)] ^= 1;
        }
      }
    }
    printf("%d\n", dp[p][(1 << p) - 1] ^ 1);
  }

  return 0;
}
