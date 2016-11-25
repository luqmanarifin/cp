#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int dp[2][N][N], p[N], u[N], dob[N];

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 1; i <= n; i++) {
    int v, w;
    scanf("%d.%d", &v, &w);
    p[i] = v * 1000000 + w * 1000;
  }
  for (int i = 1; i <= n; i++) {
    int v, w;
    scanf("%d.%d", &v, &w);
    u[i] = v * 1000000 + w * 1000;
  }
  for (int i = 1; i <= n; i++) {
    dob[i] = p[i] + u[i] - 1LL * p[i] * u[i] / 1000000;
    //printf("%d: %d %d %d\n", i, p[i], u[i], dob[i]);
  }
  for (int i = 1; i <= n; i++) {
    int st = i % 2;
    for (int j = 0; j <= a && j <= i; j++) {
      for (int k = 0; k <= b && k <= i; k++) {
        int& ret = dp[st][j][k];
        ret = dp[st^1][j][k];
        if (j) ret = max(ret, dp[st^1][j-1][k] + p[i]);
        if (k) ret = max(ret, dp[st^1][j][k-1] + u[i]);
        if (j && k) ret = max(ret, dp[st^1][j-1][k-1] + dob[i]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      ans = max(ans, dp[n % 2][i][j]);
    }
  }
  //cout << ans << endl;
  printf("%d.%.6d\n", ans / 1000000, ans % 1000000);
  return 0;
}
