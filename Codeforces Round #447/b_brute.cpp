
#include <bits/stdc++.h>

using namespace std;

int ans[15][1 << 10][2];

int main() {
  for (int n = 1; n <= 7; n++) {
    for (int m = 1; m <= 7; m++) {
      memset(ans, 0, sizeof(ans));
      ans[0][0][0] = ans[0][0][1] = 1;
      for (int i = 1; i <= n; i++) {
        for (int k = 0; k < (1 << m); k++) {
          for (int j = 0; j < (1 << m); j++) {
            if (__builtin_popcount(j) % 2) {
              ans[i][k][1] += ans[i-1][k ^ j][1];
            } else {
              ans[i][k][0] += ans[i-1][k ^ j][0];
            }
          }
        }
      }
      printf("%d %d: %d %d\n", n, m, ans[n][(1 << m) - 1][1], ans[n][0][0]);
    }
  }

  return 0;
}
