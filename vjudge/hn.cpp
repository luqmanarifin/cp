#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      long long l = i, r = n;
      while (l < r) {
        long long mid = (l + r + 1) >> 1;
        if (n / i == n / mid) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      ans += n / i * (l - i + 1);
      i = l;
    }
    printf("%lld\n", ans);
  }

  return 0;
}
