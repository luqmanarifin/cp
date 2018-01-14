#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int inf = 1e9;

int dp[N][N], a[N];

void maxi(int& at, int val) {
  at = max(at, val);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = -inf;
      }
      if (a[i] >= 0 && a[i] + r <= l) {
        dp[i][1] = a[i] / r;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dp[i][j] < 0) continue;
        for (int k = i + 1; k <= n; k++) {
          if (a[k] < a[i] + r) continue;
          if (a[k] + r > l) break;
          maxi(dp[k][j + 1], dp[i][j] + (a[k] - a[i] - r) / r);
        }
      }
    }
    int ans = n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dp[i][j] >= 0) {
          dp[i][j] += (l - a[i] - r) / r;
        }
        if (dp[i][j] >= n - j) {
          ans = min(ans, n - j);
        }
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
