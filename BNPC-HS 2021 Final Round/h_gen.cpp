#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int MOD = 10;

int main() {
  srand(time(0));
  int n = 10, q = 10000;
  printf("%d %d\n", n, q);
  for (int i = 0; i < n; i++) printf("%d ", rand() % MOD); printf("\n");
  while (q--) {
    int c = rand() % 5;
    int l = rand() % n + 1;
    int r = rand() % n + 1;
    int v = rand() % MOD;
    if (l > r) swap(l, r);
    if (c == 0) {
      printf("F %d %d %d\n", l, r, v);
    } else if (c == 1) {
      printf("I %d\n", v);
    } else if (c == 2) {
      printf("L %d %d\n", l, r);
    } else if (c == 3) {
      printf("C %d %d\n", l, r);
    } else {
      printf("O %d %d\n", l, r);
    }
  }

  return 0;
}
