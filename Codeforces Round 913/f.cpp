#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9;

int a[N], b[N], up[N], down[N], cost[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      a[n + i] = a[i];
      b[i] = a[i];
    }
    reverse(b, b + n);
    for (int i = 0; i < n; i++) {
      b[n + i] = b[i];
    }

    for (int i = 0; i <= 2 * n; i++) {
      up[i] = down[i] = 0;
      cost[i] = inf;
    }
    for (int i = 1; i < 2 * n; i++) {
      if (a[i-1] <= a[i]) {
        up[i]++;  
      }
      if (b[i-1] <= b[i]) {
        down[i]++;
      }
      up[i] += up[i-1];
      down[i] += down[i-1];
    }
    // for (int i = 0; i < 2 * n; i++) printf("%d ", up[i]); printf("\n");
    // for (int i = 0; i < 2 * n; i++) printf("%d ", down[i]); printf("\n");
    for (int i = 1; i <= n; i++) {
      int r = i + n - 1;
      if (down[r] - down[i] == n - 1) {
        cost[i % n] = 0;
      }
    }
    for (int it = 0; it < 2; it++) {
      for (int i = 0; i < n; i++) {
        cost[(i + 1) % n] = min(cost[(i + 1) % n], cost[i] + 1);
      }
    }


    int ans = inf;
    for (int shift = 0; shift < n; shift++) {
      int l = n - shift;
      int r = l + n - 1;
      if (up[r] - up[l] == n - 1) {
        ans = min(ans, shift);
      }
      ans = min(ans, ((n - shift) % n) + 1 + cost[(n - shift) % n]);
    }
    if (ans == inf) ans = -1;
    printf("%d\n", ans);
  }

  return 0;
}
