#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int inf = 2e9;

vector<int> edge[N];
int c[N], k = 1;
int dp[2][N][N];  // wajib, idx, component

void upd(int& at, int val) {
  at = max(at, val);
}

int dfs(int now, int bef) {
  int child = 0;
  vector<vector<vector<int>>> val(2, vector<vector<int>>(2, vector<int>(k+1, -inf)));
  val[0][0][0] = 0;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    child++;
    dfs(it, now);

    vector<vector<vector<int>>> fut(2, vector<vector<int>>(2, vector<int>(k+1, -inf)));
    for (int t = 0; t < 2; t++) {
      for (int r = 0; r < 2; r++) {
        for (int i = 0; i <= k; i++) {
          if (val[t][r][i] < 0) continue;
          for (int take = 0; take <= k; take++) {
            if (i+take <=k) {
              upd(fut[t][r][i+take], val[t][r][i] + dp[0][it][take]);
            }
            if (t == 0)  {
              if (r == 0) {
                if (i+take <=k) {
                  upd(fut[1][1][i+take], val[t][r][i] + dp[1][it][take]);    
                }
              }
            } else {
              if (r == 0) {
                if (i+take <=k) {
                  upd(fut[1][1][i+take], val[t][r][i] + dp[1][it][take]);    
                }
              } else {
                if (i+take-1 <= k) {
                  upd(fut[1][0][i+take-1], val[t][r][i] + dp[1][it][take]);
                }
              }
            }
          }
        }
      }
    }
    val = fut;
  }
  if (now == 1) {
    int ans = c[now];
    for (int i = 0; i <= k; i++) {
      if (i <= k - 1) {
        upd(ans, val[0][0][i] + c[now]);
      }
      upd(ans, val[1][0][i] + c[now]);
      upd(ans, val[1][1][i] + c[now]);
    }
    return ans;
  }
  if (child == 0) {
    for (int i = 0; i <= k; i++) {
      dp[0][now][i] = (i? c[now] : 0);
      dp[1][now][i] = (i? c[now] : -inf);
    }
    return 0;
  }
  for (int i = 0; i <= k; i++) {
    upd(dp[0][now][i], val[0][0][i]);
    upd(dp[0][now][i], val[1][0][i] + c[now]);
    upd(dp[0][now][i], val[1][1][i] + c[now]);

    if (i > 0) {
      upd(dp[1][now][i], val[0][0][i-1] + c[now]);
      upd(dp[1][now][i], val[1][0][i-1] + c[now]);
    }
    upd(dp[1][now][i], val[1][1][i] + c[now]);

    // printf("now:%d, %d %d: %d\n", now, 0, i, dp[0][now][i]);
    // printf("now:%d, %d %d: %d\n", now, 1, i, dp[1][now][i]);
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < N; i++) edge[i].clear();
    for (int i = 0; i < 2; i++) {
      for (int now = 0; now < N; now++) {
        for (int j = 0; j < N; j++) {
          dp[i][now][j] = -inf;
        }
      }
    }

    int n;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", c + i);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    printf("Case #%d: %d\n", tt, dfs(1, 0));
  }

  return 0;
}
