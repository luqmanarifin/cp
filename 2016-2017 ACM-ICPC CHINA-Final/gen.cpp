#include <bits/stdc++.h>

using namespace std;

int main() {
  srand(time(0));
  int tt = 6;
  printf("%d\n", tt);
  while (tt--) {
    int n = 100000;
    int m = 200000;
    int q = 200000;
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; i++) printf("%d ", rand() % n + 1);
    printf("\n");
    for (int i = 0; i < m; i++) {
      int u = rand() % n + 1;
      int v = rand() % n + 1;
      while (u == v) {
        u = rand() % n + 1;
        v = rand() % n + 1;
      }
      int w = rand() + 1;
      printf("%d %d %d\n", u, v, w);
    }
    printf("%d\n", q);
    while (q--) {
      int x = rand() % n + 1;
      int w = rand() + 1;
      printf("%d %d\n", x, w);
    }
  }
  return 0;
}