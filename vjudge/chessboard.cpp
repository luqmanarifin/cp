#include <bits/stdc++.h>

using namespace std;

int main() {
  while (1) {
    int n;
    scanf("%d", &n);
    if (n == 0) break;
    long long l = 0, r = n;
    while (l < r) {
      long long mid = (l + r + 1) >> 1;
      if (mid * mid < n) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    n -= l * l;
    long long ke = l + 1;
    int x, y;
    if (ke % 2 == 0) {
      if (n <= ke) {
        x = n;
        y = ke;
      } else {
        n -= ke;
        x = ke;
        y = ke - n;
      }
    } else {
      if (n <= ke) {
        x = ke;
        y = n;
      } else {
        n -= ke;
        x = ke - n;
        y = ke;
      }
    }
    printf("%d %d\n", x, y);
  }
  return 0;
}
