
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 100;
  printf("%d\n", n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d", rand() % 2);
    }
    printf("\n");
    
  }
  int q = 100;
  printf("%d\n", q);
  for (int i = 1; i <= q; i++) {
    printf("%d %d\n", n + i - 1, n + i - 2);
  }
  return 0;
}
