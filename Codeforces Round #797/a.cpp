#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int l = 0, r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      int tot = 3 * mid - 3;
      if (tot < n) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    int a = r;
    int b = a - 1;
    int c = n - a - b;
    if (c <= 0) {
      c = 1;
      b = n - a - c;
    }
    printf("%d %d %d\n", b, a, c);
  }

  return 0;
}
