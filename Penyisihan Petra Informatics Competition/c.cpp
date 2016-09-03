#include <bits/stdc++.h>

using namespace std;

const int N = 12;

int dp[N][1 << N][255];
int d[N][N];
int a[N];
vector<pair<int, int> > to[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    //puts("cok");
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++) {
      to[i].clear();
    }
    
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      for (int j = 0; j < n; j++) {
        scanf("%d", &d[i][j]);
      }
    }
    //puts("ontol");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[i][j] > 0) {
          to[i].push_back(make_pair(j, d[i][j]));
        }
      }
    }
    //puts("anjing");
    dp[0][1][m] = a[0];
    for (int k = m; k >= 0; k--) {
      for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask = ((mask + 1) | (1 << i))) {
          if (dp[i][mask][k] == -1) continue;
          //printf("%d %d %d\n", i, mask, k);
          for (int z = 0; z < to[i].size(); z++) {
            int j = to[i][z].first;
            int add = ((mask & (1 << j))? 0 : a[j]);
            if (k - d[i][j] >= 0) {
              dp[j][mask | (1 << j)][k - d[i][j]] = max(dp[j][mask | (1 << j)][k - d[i][j]], dp[i][mask][k] + add);
            }
          }
        }
      }
    }
    int best = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (1 << n); j++) {
        for (int k = 0; k <= m; k++) {
          best = max(best, dp[i][j][k]);
        }
      }
    }
    printf("%d\n", best);
  }

  return 0;
}
