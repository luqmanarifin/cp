#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long gcd(long long a, long long b) {
  return b? gcd(b, a % b) : a;
}

long long a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n; long long k;
    scanf("%d %lld", &n, &k);
    bool all_neg = 1, all_zero = 1, all_pos = 1;
    for (int i = 0; i < n; i++) {
      scanf("%lld", a + i);
      a[i] -= k;
      if (a[i] < 0) {
        all_zero = 0;
        all_pos = 0;
      } else if (a[i] > 0) {
        all_zero = 0;
        all_neg = 0;
      } else {
        all_pos = 0;
        all_neg = 0;
      }
    }
    if (all_zero) {
      puts("0");
      continue;
    }
    if (!all_pos && !all_neg) {
      puts("-1");
      continue;
    }
    long long fpb = abs(a[0]);
    for (int i = 0; i < n; i++) {
      fpb = gcd(fpb, abs(a[i]));
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += abs(a[i] / fpb) - 1;
    }
    printf("%lld\n", ans);
  }

  return 0;
}
