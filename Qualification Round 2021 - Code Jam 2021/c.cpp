#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N], cost[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, c;
    scanf("%d %d", &n, &c);
    printf("Case #%d:", tt);
    int l = n - 1, r = (2 + n) * (n - 1) / 2;
    if (c < l || r < c) {
      printf(" IMPOSSIBLE\n");
      continue;
    }
    for (int i = 0; i < n; i++) a[i] = i + 1, cost[i] = 1;
    c -= n - 1;
    for (int i = n - 2; i >= 0; i--) {
      if (c) {
        int here = min(c, n - i - 1);
        cost[i] += here;
        c -= here;
      }
    }
    // printf("tai "); for (int i = 0; i < n - 1; i++) printf("%d ", cost[i]); printf("\n");
    for (int i = n - 2; i >= 0; i--) {
      int p = i + cost[i] - 1;
      for (l = i, r = p; l < r; l++, r--) {
        swap(a[l], a[r]);
      }
    }
    for (int i = 0; i < n; i++) printf(" %d", a[i]); printf("\n");
  }

  return 0;
}
