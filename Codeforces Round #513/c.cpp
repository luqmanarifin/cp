#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const long long inf = 1e18;

long long a[N];
long long b[N];
long long got[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  for (int i = 0; i < m; i++) scanf("%lld", b + i);
  long long x;
  scanf("%lld", &x);
  for (int i = 1; i < m; i++) {
    b[i] += b[i - 1];
  }
  for (int i = 1; i < n; i++) {
    a[i] += a[i - 1];
  }
  fill(got, got + N, inf);
  for (int i = 0; i < m; i++) {
    for (int j = i; j < m; j++) {
      long long now = b[j] - (i? b[i - 1] : 0);
      got[j-i] = min(got[j-i], now);
    }
  }
  for (int i = m - 2; i >= 0; i--) {
    got[i] = min(got[i], got[i + 1]);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      long long now = a[j] - (i? a[i - 1] : 0);
      long long lim = x / now;
      int p = upper_bound(got, got + m, lim) - got;
      ans = max(ans, 1LL * (j - i + 1) * p);
    }
  }
  cout << ans << endl;
  return 0;
}
