#include <bits/stdc++.h>

using namespace std;

int a[200][200];

int main() {
  int n = 3;
  srand(time(0));
  for (int i = 0; i < (1 << n); i++) {
    for (int j = i + 1; j < (1 << n); j++) {
      int got = rand() % 100;
      while (got == 0) got = rand() % 100;
      int c = rand() % 2;
      a[i][j] = got;
      a[j][i] = -1;
      // if (c) swap(a[i][j], a[j][i]);
    }
  }
  printf("%d\n", n);
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < (1 << n); j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}
