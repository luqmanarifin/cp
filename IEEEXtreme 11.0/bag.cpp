#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int dp[N];
int w[N], f[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(dp, 0, sizeof(dp));
    
    int c, n;
    scanf("%d %d", &c, &n);
    for (int i = 0; i < n; i++) scanf("%d %d", w + i, f + i);
    for (int i = 0; i < n; i++) {
      for (int j = c; j >= w[i]; j--) {
        dp[j] = max(dp[j], dp[j-w[i]] + f[i]);
      }
    }
    int ans = 0;
    for (int i = 0; i <= c; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
  }

  return 0;
}
