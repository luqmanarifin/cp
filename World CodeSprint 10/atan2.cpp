#include <bits/stdc++.h>

using namespace std;

int main() {
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) continue;
      printf("%d %d: %.15f\n", i, j, atan2(j, i));
    }
  }

  return 0;
}
