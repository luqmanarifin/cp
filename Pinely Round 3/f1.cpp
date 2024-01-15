#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long mod = 998244353;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    long long ans = 1;
    if (a[1] > 1 || a[n] != n) ans = 0;
    for (int i = 1; i <= n; i++) {
      int d = a[i] - a[i - 1];
      if (d == 0) {
        continue;
      }
      long long e = (i - 1 - a[i - 1]);
      if (d == 1) {
        ans *= 2 * e + 1;
        ans %= mod;
      } else if (d == 2) {
        ans *= e * e % mod;
        ans %= mod;
      } else {
        ans = 0;
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}
