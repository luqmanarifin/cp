#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = 0;
    if (a >= b) {
      ans = a - b;
    } else {
      int len = b - a;
      ans = len % 2? len / 2 + 2 : len / 2;
    }
    printf("%d\n", ans);
  }
  return 0;
}
