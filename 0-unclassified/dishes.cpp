#include <bits/stdc++.h>

using namespace std;

const int N = 19;

long long dp[N][1 << N];
int a[N];
int c[N][N], n;

long long find(int now, int mask) {
  if(__builtin_popcount(mask) == 1) {
    return a[now];
  }
  if(dp[now][mask] != -1) {
    return dp[now][mask];
  }
  long long& ret = dp[now][mask] = 0;
  for(int i = 0; i < n; i++) {
    if(i != now && (mask & (1 << i))) {
      ret = max(ret, find(i, mask ^ (1 << now)) + a[now] + c[i][now]);
    }
  }
  return ret;
}

int main() {
  int m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  while(k--) {
    int u, v, d;
    scanf("%d %d %d", &u, &v, &d);
    u--; v--;
    c[u][v] = d;
  }
  memset(dp, -1, sizeof(dp));
  long long ans = 0;
  for(int mask = 0; mask < (1 << n); mask++) {
    if(__builtin_popcount(mask) != m) {
      continue;
    }
    for(int i = 0; i < n; i++) {
      if((mask & (1 << i)) == 0) {
        continue;
      }
      ans = max(ans, find(i, mask));
    }
  }
  cout << ans << endl;
  return 0;
}
