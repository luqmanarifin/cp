#include <bits/stdc++.h>

using namespace std;

const int MAX = (1 << 15);
const int POL = 1e9;

int get_rand() {
  return rand() * MAX + rand();
}

int main() {
  srand(time(0));
  int n = 100000;
  printf("%d\n", n);
  for (int i = 0; i < n; i++) {
    int x = get_rand() % POL;
    int y = get_rand() % POL;
    int d = get_rand() % 4 * 90;
    printf("%d %d %d\n", x, y, d);
  }
  int q = 200000;
  printf("%d\n", q);
  while (q--) {
    int t = get_rand() % 2 + 1;
    if (t == 1) {
      int x = get_rand() % POL;
      int y = get_rand() % POL;
      int l = get_rand() % n;
      int r = get_rand() % n;
      if (l > r) swap(l, r);
      printf("%d %d %d %d %d\n", 1, x, y, l + 1, r + 1);
    } else {
      int u = get_rand() % n;
      int x = get_rand() % POL;
      int y = get_rand() % POL;
      int b = get_rand() % 4 * 90;
      printf("%d %d %d %d %d\n", 2, u, x, y, b);
    }
  }
  
  return 0;
}
