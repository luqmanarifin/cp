#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int ans = inf;
    int l = min(n, m);
    int r = max(n, m);
    if (k + 1 <= l && 2 * k + 3 <= r) {
      if (k == 1) {
        ans = min(ans, 5);
      } else {
        ans = min(ans, 4);
      }
    }
    if (2*k + 1 <= l && 2*k + 3 <= r) {
      ans = min(ans, l / k + (l % k? 1 : 0));
    }
    if (ans == inf) ans = -1;
    if (tt <= 100) printf("Case #%d: %d %d %d %d\n", tt, ans, ans, ans, ans);
  }

  return 0;
}
