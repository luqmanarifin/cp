#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, e;
    scanf("%d %d", &e, &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    int ans = 0;
    for (int steal = 0; steal <= n; steal++) {
      int honor = 0, energy = e, p = 0;
      bool valid = 1;

      while (p < n - steal) {
        if (energy > a[p]) {
          energy -= a[p];
          honor++;
          p++;
        } else {
          break;
        }
      }

      for (int i = 0; i < steal; i++) {
        if (honor == 0) {
          valid = 0;
          break;
        }
        honor--;
        energy += a[n - i - 1];

        while (p < n - steal) {
          if (energy > a[p]) {
            energy -= a[p];
            honor++;
            p++;
          } else {
            break;
          }
        }
      }
      if (valid) {
        ans = max(ans, honor);
      }
    }
    printf("Case #%d: %d\n", tt, ans);
  }

  return 0;
}
