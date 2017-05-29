#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n, h[N];

long long pre(int n) {
  return 1LL * n * (n + 1) / 2;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      sum += a[i];
      h[i] = min(i, n - i + 1);
    }
    int now = 1e9;
    for (int i = 1; i <= n; i++) {
      now = min(now + 1, a[i]);
      h[i] = min(h[i], now);
    }
    now = 1e9;
    for (int i = n; i >= 1; i--) {
      now = min(now + 1, a[i]);
      h[i] = min(h[i], now);
    }
    int p = -1;
    for (int i = 1; i <= n; i++) p = max(p, h[i]);
    printf("%lld\n", sum - pre(p) - pre(p - 1));
  }

  return 0;
}
