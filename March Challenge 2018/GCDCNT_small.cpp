
#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, l, r, v;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d %d", &l, &v);
      a[l] = v;
    } else {
      scanf("%d %d %d", &l, &r, &v);
      int ans = 0;
      for (int i = l; i <= r; i++) if (__gcd(v, a[i]) == 1) ans++;
      printf("%d\n", ans);
    }
  }

  return 0;
}
