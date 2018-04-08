#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int a[N][N];
int m[N];
int contain[N][N * N], dp[N * N][N];
int cnt[N * N];

int main() {
  int n, tt = 0;
  while (scanf("%d", &n) == 1) {    
    vector<int> uniq;
    memset(contain, 0, sizeof contain);
    memset(dp, 0, sizeof dp);
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++) {
      scanf("%d", m + i);
      for (int j = 0; j < m[i]; j++) {
        scanf("%d", &a[i][j]);
        uniq.push_back(a[i][j]);
      }
    }
    sort(uniq.begin(), uniq.end());
    uniq.resize(distance(uniq.begin(), unique(uniq.begin(), uniq.end())));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m[i]; ++j) {
        a[i][j] = lower_bound(uniq.begin(), uniq.end(), a[i][j]) - uniq.begin();
        contain[i][a[i][j]] = 1;
      }
    }
    int s = uniq.size();
    int all_comp = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < s; ++j)
        if (contain[i][j])
          ++all_comp, ++cnt[j];
    for (int i = 0; i + 1 < s; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          if (k == j) {
            //~ cerr << i << " cnt " << j << " " << cnt[i] << endl;
            if (cnt[i] > 1) continue;
            dp[i+1][k] = max(dp[i+1][k], dp[i][j] + (contain[k][i] && contain[k][i+1]));
          }
          else
            dp[i+1][k] = max(dp[i+1][k], dp[i][j] + (contain[k][i] && contain[k][i+1]));
        }
        dp[i+1][n] = max(dp[i+1][n], dp[i][j]);
      }
      dp[i+1][n] = max(dp[i+1][n], dp[i][n]);
      for (int k = 0; k < n; ++k) {
        dp[i+1][k] = max(dp[i+1][k], dp[i][n] + (contain[k][i] && contain[k][i+1]));
      }
    }
    int connector = 0;
    for (int i = 0; i <= s; ++i)
      for (int j = 0; j <= n; ++j) {
        connector = max(connector, dp[i][j]);
        //~ cerr << i << " " << j << " " << dp[i][j] << endl;;
      }
    //~ cerr << connector << " " << all_comp << endl;
    int comp = all_comp - connector;
    int ans = 2 * (comp - 1) - (n - 1);
    printf("Case %d: %d\n", ++tt, ans);
  }
  return 0;
}
