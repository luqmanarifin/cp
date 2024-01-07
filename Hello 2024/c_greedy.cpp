#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int x = n, y = n, ans = 0;
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      if (v <= x) {
        x = v;
      } else if (y < v) {
        x = v;
        ans++;
      } else {
        y = v;
      }
      if (x > y) swap(x, y);
    }
    printf("%d\n", ans);
  }

  return 0;
}
