#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const int inf = 1e9;

long long a[N];
int dp[N][N], best[N][N];

long long get(int l, int r) {
  return a[r] - (l? a[l - 1] : 0);
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    a[i] += a[i - 1];
  }
  for(int i = 1; i <= n; i++) {
    dp[1][i] = 1;
    for(int j = 2; j <= i; j++) {
      int l = 1, r = j - 1;
      while(l < r) {
        int mid = (l + r) >> 1;
        if(get(mid, j - 1) <= get(j, i)) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      if(get(l, j - 1) <= get(j, i) && best[l][j - 1]) {
        dp[j][i] = best[l][j - 1] + 1;
      }
    }
    for(int j = i; j >= 1; j--) {
      best[j][i] = max(dp[j][i], best[j + 1][i]);
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}
