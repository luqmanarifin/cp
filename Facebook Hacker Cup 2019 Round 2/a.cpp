#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int a, b;
    scanf("%d %d", &a, &b);
    int c, d, e, f;
    if (k == 1) {
      scanf("%d %d", &c, &d);
    } else {
      scanf("%d %d %d %d", &c, &d, &e, &f);
    }
    printf("Case #%d: ", tt);
    if (k == 1) {
      printf("N\n");
      continue;
    }
    int p = (a + b) % 2;
    int q = (c + d) % 2;
    int r = (e + f) % 2;
    if (p == q && q == r) {
      printf("Y\n");
    } else {
      printf("N\n");
    }
  }

  return 0;
}