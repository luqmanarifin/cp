#include <bits/stdc++.h>

using namespace std;

int main() {
  srand(time(0));
  int n = 10, m = 50;
  printf("%d %d\n", n, m);
  for (int i = 0; i < m; i++) printf("%d %d\n", rand() % n + 1, rand() % n + 1);
  int q = n * n;
  printf("%d\n", q);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("2 %d %d\n", i, j);
    }
  }
  return 0;
}
