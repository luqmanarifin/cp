#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 1e5;
  printf("%d %d\n", n, n);
  srand(time(NULL));
  for(int i = 0; i < n; i++) printf("%d ", rand() % ((int)1e9) + 1);
  for(int i = 0; i < n; i++) {
    int a[5];
    for(int j = 0; j < 5; j++) {
      a[j] = rand() % n + 1;
      printf("%d ", a[j]);
    }
    printf("\n");
  }
  return 0;
}