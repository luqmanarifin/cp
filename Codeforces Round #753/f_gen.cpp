#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 2000, m = 2000;
  printf("%d\n%d %d\n", 1, n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%c", 'R');
    }
    printf("\n");
  }

  return 0;
}
