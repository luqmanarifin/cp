
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 1000;
  printf("%d\n", n);
  srand(time(0));
  for (int i = 0; i < 4; i++) printf("%d ", rand() % 1000 + 1); printf("\n");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c", rand() % 2? '*' :'.');
    }
    printf("\n");
  }
  return 0;
}
