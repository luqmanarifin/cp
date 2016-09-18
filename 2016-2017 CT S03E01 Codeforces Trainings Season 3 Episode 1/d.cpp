#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    scanf("%I64d", &n);
    if (n == 0) {
      puts("0");
      continue;
    }
    long long ans = (n + 1) / 2;
    long long l = 0, r = (n - 1) / 2;
    while (l < r) {
      long long mid = (l + r) >> 1;
      if ((mid*2 + 1)*3 + 1 <= n) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    ans += (n - 1) / 2 - l + 1;
    printf("%I64d\n", ans);
  }

  return 0;
}
