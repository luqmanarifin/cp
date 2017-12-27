#include <bits/stdc++.h>

using namespace std;

int a[105];

int main() {
  for (int n = 1; n <= 12; n++) {
    for (int i = 1; i <= n; i++) a[i] = i;
    bool found = 0;
    do {
      bool ok = 1;
      for (int i = 1; i <= n; i++) {
        if ((a[i] & i) == 0 || a[i] == i) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        found = 1;
        for (int i = 1; i <= n; i++) printf("%d ", a[i]); printf("\n");
        break;
      }
    } while (next_permutation(a + 1, a + 1 + n));
    if (!found) {
      printf("%d not found\n", n);
    }
  }

  return 0;
}
