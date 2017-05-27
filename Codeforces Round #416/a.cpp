#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  for (int it = 1; ; it++) {
    if (it % 2) {
      if (a < it) {
        puts("Vladik");
        return 0;
      }
      a -= it;
    } else {
      if (b < it) {
        puts("Valera");
        return 0;
      }
      b -= it;
    }
  }

  return 0;
}
