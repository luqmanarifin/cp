#include <bits/stdc++.h>

using namespace std;

int main() {
  srand(time(0));
  int t = 20;
  printf("%d\n", t);
  while (t--) {
    int n = 50000;
    int L = 1;
    int R = 10000000;
    printf("%d %d %d\n", n, L, R);
    for (int i = 0; i < n; i++) printf("%d ", rand() % 10000000 + 1); printf("\n");
    for (int i = 1; i < n; i++) printf("%d %d\n", i, i + 1);
  }
  return 0;
}
