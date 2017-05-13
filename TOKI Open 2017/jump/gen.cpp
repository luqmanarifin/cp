#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 200;
  int q = 300000;
  srand(time(NULL));
  printf("%d %d\n", n, q);
  for (int i = 0; i < n; i++) printf("%d", rand() % 10); printf("\n");
  while (q--) {
    int l = rand() % n;
    int r = rand() % n;
    if (l > r) swap(l, r);
    if (l == r) r++;
    assert(r <= n);
    assert(l < r);
    int k = rand() % (n - 1) + 1;
    printf("%d %d %d\n", l, r, k);
  }

  return 0;
}