#include <bits/stdc++.h>

using namespace std;

int main() {
  int t = 5;
  printf("%d\n", t);
  srand(time(0));
  while (t--) {
    int n = 100, m = 1000, k = rand() % 2 + 1;
    printf("%d %d %d\n", n, m, k);
    while (m--) {
      int u = rand() % n + 1;
      int v = rand() % n + 1;
      while (u == v) u = rand() % n + 1, v = rand() % n + 1;
      assert(u != v);
      if (u > v) swap(u, v);
      printf("%d %d\n", u, v);
    }
  }
  
  return 0;
}
