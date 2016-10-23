#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int main() {
  srand(time(0));
  int t = 20;
  printf("%d\n", t);
  while (t--) {
    int n = 1000;
    int q = 1000;
    printf("%d %d\n", n, q);
    for (int i = 0; i < n; i++) printf("%d ", rand() % 1000 + 1);
    for (int i = 0; i < n; i++) printf("%d ", rand() % 1000 + 1);
    while (q--) {
      printf("%d %d\n", rand() % 1000 + 1, rand() % 1000 + 1);
    }
  }

  return 0;
}
