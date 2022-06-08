#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int odd = 0, even = 0, mn = 1e9;
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      if (v % 2) {
        odd++;
      } else {
        even++;
        for (int j = 0; j < 64; j++) {
          if (v & (1 << j)) {
            mn = min(mn, j);
            break;
          }
        }
      }
    }
    int ans = 0;
    if (odd > 0) {
      ans = even;
    } else {
      ans = mn + even - 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
