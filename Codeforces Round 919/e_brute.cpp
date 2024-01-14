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

  for (int k = 1; k <= 10; k++) {
    for (int n = k; n <= 10; n++) {
  
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
          for (int x = 0; x + 1 + j <= k; x++) {
            int good = (j + 1) * (x + 1);
            if (i + good <= n) {
              add(dp[i + good][x], dp[i][j]);
            }
          }
        }
      }
      int ans = 0;
      for (int j = 0; j <= k; j++) add(ans, dp[n][j]);
      printf("%d %d: %d\n", n, k, ans);
  
    }
  }

  return 0;
}
