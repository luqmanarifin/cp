#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 5;

int a[N];

main() {
  int t;
  scanf("%lld", &t);
  while (t--) {
    int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    int now = 1, sum = a[1];
    int ans = 0;
    while (now < n) {
      ans++;
      int from = now, add = sum;
      now += sum;
      for (int i = from + 1; i <= n && i <= from + add; i++) {
        sum += a[i];
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}
