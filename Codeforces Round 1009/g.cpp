#include <bits/stdc++.h>

using namespace std;

const long long N = 405;

long long a[N], dp[N][N];

long long solve(int l, int r) {
  if (r - l + 1 < 3) return 0;
  if (dp[l][r] != -1) return dp[l][r];
  long long ans = 0;
  for (int i = l; i < r; i++) {
    ans = max(ans, solve(l, i) + solve(i + 1, r));
  }
  for (int i = l + 1; i < r; i++) {
    long long cur = a[i] * a[l] * a[r];
    cur += solve(l + 1, i - 1);
    cur += solve(i + 1, r - 1);
    ans = max(ans, cur);
  }
  return dp[l][r] = ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = -1;
      }
    }
    long long ans = solve(1, n - 1);
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        long long cur = a[0] * a[i] * a[j];
        cur += solve(1, i - 1);
        cur += solve(i + 1, j - 1);
        cur += solve(j + 1, n - 1);
        ans = max(ans, cur);
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}
