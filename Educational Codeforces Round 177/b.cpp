#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k; long long x;
    scanf("%d %d %lld", &n, &k, &x);
    long long sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      sum += a[i];
    }
    long long pre = 0;
    for (int i = n - 1; i >= 0; i--) {
      pre += a[i];
      int l = 0, r = k;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (pre + mid * sum >= x) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      ans += k - l;
    }
    printf("%lld\n", ans);
  }

  return 0;
}
