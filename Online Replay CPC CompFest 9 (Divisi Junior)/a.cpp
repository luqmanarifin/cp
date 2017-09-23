#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", a + i);
  sort(a + 1, a + 1 + n);
  if (n == 1) {
    cout << a[1] << endl;
  } else {
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    long long ans = -1e18;
    for (int i = 1; i < n; i++) {
      long long cur = -a[i] + (a[n] - a[i]);
      ans = max(ans, cur);
    }
    cout << ans << endl;
  }

  return 0;
}
