#include <bits/stdc++.h>

using namespace std;

int main() {
  for (int x = 1; x <= 10; x++) {
    for (int y = 1; y <= 10; y++) {
      // printf("iterate %d %d\n", x, y);
      bool found = 0;
      for (int i = 0; i <= 16; i++) {
        if (((x + i) & (y + i)) == 0) {
          found = 1;
          printf("%d %d: ans %d\n", x, y, i);
          break;
        }
      }
      if (!found) {
        printf("%d %d: no answer\n", x, y);
      }
    }
  }

  return 0;
}
