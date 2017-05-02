#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

const int N = 3005;

long long dp[N][N];
int a[N];

int main() {
  dp[1][0] = 1;
  dp[2][1] = 2;
  for (int n = 3; n <= 11; n++) {
    for (int i = 0; i < n; i++) a[i] = i;
    do {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        int cur = 0;
        cur |= (i + 1 < n && a[i] < a[i + 1]);
        cur |= (i - 1 >= 0 && a[i - 1] > a[i]);
        cnt += cur;
      }
      dp[n][cnt]++;
    } while (next_permutation(a, a + n));
    //for (int j = n; j >= 1; j--) dp[n][j] += dp[n][j+1];
    for (int j = 1; j <= n; j++) printf("%d %d: %d\n", n, j, dp[n][j]);
  }
    
  return 0;
}
