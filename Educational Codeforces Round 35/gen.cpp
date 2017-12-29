#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int main() {
  srand(time(0));
  int n = 1000;
  printf("%d\n", n);
  for (int i = 0; i < n; i++) printf("%d ", rand() % 100 + 1); printf("\n");
  int q = 1000;
  printf("%d\n", q);
  while (q--) {
    int l = rand() % n + 1;
    int r = rand() % n + 1;
    int x = rand() % 100 + 1;
    int y = rand() % 100 + 1;
    if (l > r) swap(l, r);
    printf("%d %d %d %d\n", l, r, x, y);
  }

  return 0;
}
