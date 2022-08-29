#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int min_x = 0, min_y = 0, max_x = 0, max_y = 0;
    while (n--) {
      int a, b;
      scanf("%d %d", &a, &b);
      min_x = min(min_x, a);
      max_x = max(max_x, a);
      min_y = min(min_y, b);
      max_y = max(max_y, b);
    }
    int ans = 2 * (max_x - min_x) + 2 * (max_y - min_y);
    printf("%d\n", ans);
  }

  return 0;
}
