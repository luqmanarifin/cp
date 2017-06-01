#include <bits/stdc++.h>

using namespace std;

int main() {
  srand(time(0));
  int n = 100000, q = 1000;
  printf("%d %d\n", n, q);
  for (int i = 2; i <= n; i++) {
    printf("%d %d\n", i, rand() % (i - 1) + 1);
  }
  while (q--) {
    int t = rand() % 3, x, y, a, b;
    x = rand() % n;
    y = rand() % n;
    a = rand() % 1000;
    b = rand() % 1000;
    if (t == 0) {
      printf("c %d %d %d %d\n", x, y, a, b);
    } else if (t == 2) {
      printf("q %d %d\n", x, y);
    } else {
      printf("l %d\n", x);
    }
  }
  return 0;
}
