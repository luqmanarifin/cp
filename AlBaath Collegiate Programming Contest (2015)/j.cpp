#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int n, p, q;
long long a[N];
int dp[N][N];
int to[N][2];

bool can(long long w) {
  for(int i = 0; i < n; i++) {
    to[i][0] = lower_bound(a, a + n, a[i] + w) - a;
    to[i][1] = lower_bound(a, a + n, a[i] + 2 * w) - a;
  }
  for(int i = 0; i <= p; i++) {
    for(int j = 0; j <= q; j++) {
      dp[i][j] = -1;
    }
  }
  dp[p][q] = 0;
  for(int i = p; i >= 0; i--) {
    for(int j = q; j >= 0; j--) {
      if(dp[i][j] == -1) continue;
      if(dp[i][j] == n) return 1;
      if(i) {
        dp[i - 1][j] = max(dp[i - 1][j], to[dp[i][j]][0]);
      }
      if(j) {
        dp[i][j - 1] = max(dp[i][j - 1], to[dp[i][j]][1]);
      }
    }
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d %d", &n, &p, &q);
    for(int i = 0; i < n; i++) {
      scanf("%I64d", a + i);
    }
    sort(a, a + n);
    if(p + q >= n) {
      puts("1");
      continue;
    }
    int l = 1, r = 1e9;
    while(l < r) {
      int mid = (l + r) >> 1;
      if(can(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    printf("%d\n", l);
  }
  return 0;
}
