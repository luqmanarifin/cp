#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    long long mn = 1e18, mx = -1;
    for (int i = 0; i < n; i++) {
      scanf("%lld", a + i);
      mn = min(mn, a[i]);
      mx = max(mx, a[i]);
    }
    for (int i = 0; i < n; i++) scanf("%lld", b + i);
    set<long long> s;
    for (int i = 0; i < n; i++) {
      if (b[i] != -1) {
        s.insert(a[i] + b[i]);
      }
    }
    if (s.size() > 1) {
      puts("0");
      continue;
    }
    if (s.size() == 1) {
      long long tot = *(s.begin());
      int ans = 1;
      for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
          long long p = tot - a[i];
          if (p < 0 || k < p) {
            ans = 0;
            break;
          }
        }
      }
      printf("%d\n", ans);
      continue;
    }
    long long l = mx;
    long long r = mn + k;
    long long d = r - l + 1;
    printf("%lld\n", d);
  }

  return 0;
}
