#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c, ans;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b) {
      ans = c;
    } else if (a == c) {
      ans = b;
    } else {
      ans = a;
    }
    printf("%d\n", ans);
  }

  return 0;
}
