#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long inf = 1e18;

long long a[N], b[N], sa[N], sb[N];

long long find_a(int l, int r) {
  if (r < l) return 0;
  return sa[r] - sa[l - 1];
}

long long find_b(int l, int r) {
  if (r < l) return 0;
  return sb[r] - sb[l - 1];
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    for (int i = 1; i <= m; i++) scanf("%lld", b + i);
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);

    for (int i = 1; i <= n; i++) sa[i] = sa[i - 1] + a[i];
    for (int i = 1; i <= m; i++) sb[i] = sb[i - 1] + b[i];
    a[n + 1] = inf;
    b[m + 1] = inf;

    long long ans = 0;
    for (int i = 0; i <= n; i++) {
      int j = n - i;
      if (a[i] <= b[m + 1 - i] && b[j] <= a[n + 1 - j]) {
        long long lef = find_b(m + 1 - i, m) - find_a(1, i);
        long long rig = find_a(n + 1 - j, n) - find_b(1, j); 
        long long cur = lef + rig;
        ans = max(ans, cur);
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}
