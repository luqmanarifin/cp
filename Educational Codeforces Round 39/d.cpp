
#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int inf = 1e9;

char s[N][N];
int dp[N], c[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  fill(dp, dp + N, inf);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    fill(c, c + N, inf);
    vector<int> a;
    for (int j = 0; j < m; j++) if (s[i][j] == '1') a.push_back(j);
    for (int skip = 0; skip < a.size(); skip++) {
      for (int j = 0; j <= skip; j++) {
        c[skip] = min(c[skip], a[j+a.size()-skip-1] - a[j] + 1);
      }
    }
    c[a.size()] = 0;
    //for (int j = 0; j <= a.size(); j++) printf("cost %d: %d\n", j, c[j]);
    for (int j = N - 1; j >= 0; j--) {
      dp[j] += c[0];
      for (int k = 1; k <= j; k++) {
        dp[j] = min(dp[j], dp[j-k] + c[k]);
      }
    }
  }
  int ans = inf;
  for (int i = 0; i <= k; i++) ans = min(ans, dp[i]);
  cout << ans << endl;
  return 0;
}
