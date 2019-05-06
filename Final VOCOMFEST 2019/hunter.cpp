#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 105;
const int inf = 1e9;

int dp[N][N][25], h[N];
vector<int> edge[N];

int best[N], to[N];

void upd(int& at, int val) {
  at = max(at, val);
}

main() {
  int n, m, s, t;
  scanf("%lld %lld %lld %lld", &n, &m, &s, &t);
  for (int i = 1; i <= n; i++) scanf("%lld", h + i);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%lld %lld", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < 25; k++) {
        dp[i][j][k] = -inf;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (auto it : edge[i]) {
      dp[i][it][0] = h[it];
    }
    dp[i][i][0] = 0;
  }
  for (int k = 1; k < 25; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int mid = 1; mid <= n; mid++) {
          upd(dp[i][j][k], dp[i][mid][k-1] + dp[mid][j][k-1]);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) best[i] = -inf;
  best[s] = h[s];
  for (int k = 0; k <= 20; k++) {
    if (t & (1 << k)) {
      for (int i = 1; i <= n; i++) to[i] = -inf;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          upd(to[j], best[i] + dp[i][j][k]);
        }
      }
      for (int i = 1; i <= n; i++) best[i] = to[i];
    }
  }
  cout << max(0LL, best[s]) << endl;
}
