#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const long long inf = 1e18;

long long a[N], dp[N][N];

long long get(int l, int r) {
  return a[r] - a[l - 1];
}

int main() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      dp[i][j] = inf;
    }
  }
  
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    a[i] += a[i - 1];
  }
  dp[0][0] = 0;
  for(int i = 1; i <= n; i++) {
    dp[i][1] = a[i];
  }
  for(int i = 2; i <= n; i++) {
    for(int j = 2; j <= n; j++) {
      int l = 1, r = i - 1;
      while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(dp[mid][j - 1] <= get(mid + 1, i) || dp[mid][j - 1] == inf) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      if(dp[l][j - 1] <= get(l + 1, i)) {
        dp[i][j] = get(l + 1, i);
        //printf("%d %d : %d\n", i, j, dp[i][j]);
      }
    }
  }
  for(int j = 1; j <= n; j++) {
    for(int i = 1; i <= n; i++) {
      printf("%lld ", dp[i][j]);
    }
    printf("\n");
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(dp[i][j] != inf) {
        ans = max(ans, j);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
