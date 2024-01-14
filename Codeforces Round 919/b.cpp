#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], s[N];

int sum(int l, int r) {
  if (r < l) return 0;
  return s[r] - s[l - 1];
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    int ans = -2e9;
    for (int rem = 0; rem <= k; rem++) {
      int mul = min(n - rem, x);
      int cur = -sum(n - rem - mul + 1, n - rem) + sum(1, n - rem - mul);
      ans = max(ans, cur);
    }
    printf("%d\n", ans);
  }

  return 0;
}
