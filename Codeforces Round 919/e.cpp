#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
const int N = 2505;

int dp[N][N];

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        dp[i][j] = 0;
      }
    }
    for (int i = 0; i < k; i++) {
      for (int j = 0; i + 1 + j <= k; j++) {
        int add = (i + 1) * (j + 1);
        if (add <= n) {
          dp[add][j]++;
        }
      }
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < k; j++) {
        if (dp[i][j] == 0) continue;
        for (int x = 0; x + 1 + j <= k; x++) {
          int good = (j + 1) * (x + 1);
          if (i + good <= n) {
            add(dp[i + good][x], dp[i][j]);
          } else {
            break;
          }
        }
      }
    }
    int ans = 0;
    for (int j = 0; j <= k; j++) add(ans, dp[n][j]);
    printf("%d\n", ans);
  }

  return 0;
}
