#include <bits/stdc++.h>

using namespace std;

int main() {
  int t = 12;
  int n = 50;
  printf("%d\n", t);
  while (t--) {
    printf("%d\n", n);
    for (int k = 0; k < 3; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          printf("%d ", rand() % 1000000);
        }
        printf("\n");
      }
    }
  }

  return 0;
}
