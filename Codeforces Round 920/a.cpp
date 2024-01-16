#include <bits/stdc++.h>

using namespace std;

int a[5], b[5];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 4; i++) scanf("%d %d", a + i, b + i);
    int s = max(abs(a[1] - a[0]), abs(b[1] - b[0]));
    printf("%d\n", s * s);
  }

  return 0;
}
