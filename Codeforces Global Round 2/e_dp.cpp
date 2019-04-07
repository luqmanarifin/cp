#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int inf = 1e9;
const int MAGIC = 50;

int a[N];
int dp[N][MAGIC];

void upd(int& at, int val) {
  at = max(at, val);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < MAGIC; j++) {
      dp[i][j] = -inf;
    }
  }
  dp[n][0] = 0;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < MAGIC; j++) {
      for (int k = 0; k < MAGIC; k++) {
        int need = 0, got = 0;
        if (k < j) {
          need = abs(j - k);
          got = abs(j - k);
        } else if (k > j) {
          need = 2 * abs(j - k);
        }
        if (a[i] >= need) {
          int full = (a[i] - need) / 3;
          upd(dp[i-1][k], dp[i][j] + full + got);
        }
      }
    }
  }
  int ans = 0;
  for (int j = 0; j < MAGIC; j++) upd(ans, dp[0][j]); 
  cout << ans << endl;
  return 0;
}
