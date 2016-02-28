#include <bits/stdc++.h>

using namespace std;

int a[16][16];

int main() {
  int t = 250;
  printf("%d\n", t);
  while(t--) {
    int n = 16;
    for(int i = 0; i < n; i++) {
      for(int j = i + 1; j < n; j++) {
        a[i][j] = rand() % 2;
        a[j][i] = !a[i][j];
      }
    }
    printf("%d\n", n);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
