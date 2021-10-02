#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int inf = 1e9;

int a[N], c[N];
int dp[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    c[i] = i - a[i];
  }
  dp[0] = 0;
  for (int i = 1; i < N; i++) dp[i] = -1e9;
  for (int i = 1; i <= n; i++) {
    int prev = -inf;
    if (c[i] >= 0) {
      prev = dp[c[i]];
    }
    for (int j = i; j >= 1; j--) dp[j] = max(dp[j], dp[j-1]);
    if (c[i] >= 0) {
      dp[c[i]] = max(dp[c[i]], prev + 1);
    }
    for (int j = 0; j <= i; j++) printf("%d ", dp[j]); printf("\n");
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) ans = max(ans, dp[i]);
  cout << ans << endl;
  return 0;
}
