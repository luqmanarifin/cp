#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N], n;
long long sa[N], sb[N];

long long find(long long t) {
  int p = lower_bound(a + 1, a + 1 + n, (int) t) - a;
  return sb[p] - (n + 1 - p) * t + (p - 1) * t - sa[p - 1];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) sa[i] = sa[i - 1] + a[i];
  for (int i = n; i >= 1; i--) sb[i] = sb[i + 1] + a[i];
  
  long long l = -1e9, r = 1e9;
  while (r - l > 3) {
    long long lf = l + (r - l) / 3;
    long long rf = r - (r - l) / 3;
    if (find(lf) <= find(rf)) {
      r = rf;
    } else {
      l = lf;
    }
  }
  long long best = 1e18, ans = -1;
  for (long long i = l; i <= r; i++) {
    long long cur = find(i);
    if (cur < best) {
      best = cur;
      ans = i;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
