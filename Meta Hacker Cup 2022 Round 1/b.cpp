#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const long long mod = 1e9 + 7;

int a[N], b[N];

void add(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", a + i, b + i);
    long long sum_a = 0, sq_a = 0, sum_b = 0, sq_b = 0;
    for (int i = 0; i < n; i++) {
      add(sum_a, a[i]);
      add(sum_b, b[i]);
      add(sq_a, 1LL * a[i] * a[i] % mod);
      add(sq_b, 1LL * b[i] * b[i] % mod);
    }
    long long ans = 0;
    int q;
    scanf("%d", &q);
    while (q--) {
      long long x, y;
      scanf("%lld %lld", &x, &y);
      ans += 1LL * n * x % mod * x % mod - 2 * sum_a * x % mod + sq_a;
      ans += 1LL * n * y % mod * y % mod - 2 * sum_b * y % mod + sq_b;
      ans %= mod;
      if (ans < 0) ans += mod;
    }
    printf("Case #%d: %lld\n", tt, ans);
  }

  return 0;
}
