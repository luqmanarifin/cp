#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c, n, m;
  scanf("%I64d %I64d %I64d %I64d %I64d", &a, &b, &c, &n, &m);
  if (n < c || m < c) {
    cout << min(n, m) << endl;
    return 0;
  }
  n -= c;
  m -= c;
  long long ans = 1e18;
  if (a > n && b > m) {
    ans = min(ans, c + min(n, m));
  } else if (a > n) {
    ans = min(ans, c + n);
  } else if (b > m) {
    ans = min(ans, c + m);
  } else {
    ans = min(ans, c + a + b);
  }
  cout << ans << endl;
  return 0;
}
