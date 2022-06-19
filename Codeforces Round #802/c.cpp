#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N], pre[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", a + i);
      pre[i] = 0;
    }

    long long suf = 0;
    b[1] = a[1];
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      if (i + 1 <= n) {
        if (a[i] < a[i + 1]) {
          suf += a[i + 1] - a[i];
          ans += a[i + 1] - a[i];
        } else {
          pre[i] = a[i] - a[i + 1];
          ans += a[i] - a[i + 1];
        }
        b[i + 1] = a[i + 1] - suf;
      }
    }
    long long now = 0, mini = 1e18;
    for (int i = n; i >= 1; i--) {
      now += pre[i];
      b[i] -= now;
      mini = min(mini, b[i]);
    }
    ans += abs(mini);
    printf("%lld\n", ans);
  }

  return 0;
}
