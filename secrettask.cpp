#include <bits/stdc++.h>

using namespace std;

const int N = 155;
const int inf = 1e9;

int a[N];
int dp[N][N * N], tmp[N][N * N];

int main() {
  int n, ambil, s;
  scanf("%d %d %d", &n, &ambil, &s);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  if(s > n * (n + 1) / 2) {
    sort(a + 1, a + 1 + n);
    int sum = 0;
    for(int i = 1; i <= ambil; i++) {
      sum += a[i];
    }
    cout << sum << endl;
    return 0;
  }
  s += ambil * (ambil + 1) / 2;
  for(int j = 0; j < N; j++) {
    for(int k = 0; k < N * N; k++) {
      dp[j][k] = inf;
    }
  }
  dp[0][0] = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N * N; k++) {
        tmp[j][k] = dp[j][k];
      }
    }
    for(int j = 0; j <= i; j++) {
      for(int k = 0; k <= s; k++) {
        dp[j][k] = tmp[j][k];
        if(j > 0 && k - i >= 0) {
          dp[j][k] = min(dp[j][k], tmp[j - 1][k - i] + a[i]);
        }
      }
    }
  }
  int ans = inf;
  for(int k = 0; k <= s; k++) {
    ans = min(ans, dp[ambil][k]);
  }
  cout << ans << endl;
  return 0;
}
