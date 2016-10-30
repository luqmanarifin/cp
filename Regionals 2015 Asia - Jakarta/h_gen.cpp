#include <bits/stdc++.h>

using namespace std;

const int POL = 1e6;

int main() {
  srand(time(0));
  
  int t = 100;
  printf("%d\n", t);
  while (t--) {
    int n = 100, m = 500, a = rand() % POL + 1, b = rand() % POL + 1;
    printf("%d %d %d %d\n", n, m, a, b);
    for (int i = 0; i < n; i++) printf("%d ", rand() % POL); printf("\n");
    for (int i = 0; i < m; i++) {
      printf("%d %d\n", rand() % POL, rand() % POL);
    }
  }

  return 0;
}
