#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 2e18;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      sum += a[i];
    }
    long long ans = -inf, now = -inf;
    for (int i = 0; i < n; i++) {
      now = max(now + a[i], 1LL * a[i]);
      ans = max(ans, now);
    }
    if (k > 1) {
      long long suf = 0, pre = 0, adas = 0, adap = 0;
      now = 0;
      for (int i = 0; i < n; i++) {
        now += a[i];
        if (now > pre) {
          pre = now;
          adap = 1;
        } else if (now == pre) {
          adap++;
        }
      }
      now = 0;
      for (int i = n - 1; i >= 0; i--) {
        now += a[i];
        if (now > suf) {
          suf = now;
          adas = 1;
        } else if (now == suf) {
          adas++;
        }
      }
      long long take = sum * (k - 2) + adas + adap;
      if (take) {
        ans = max(ans, sum * (k - 2) + suf + pre);
      }
      if (adas + adap) {
        ans = max(ans, suf + pre);
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}
