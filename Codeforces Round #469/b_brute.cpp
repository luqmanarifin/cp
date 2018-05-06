
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  for (int n = 1; n <= 10; n++) {
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) a[2 * i - 1] = i;
    for (int i = 2*n - 1; i >= 1; i--) {
      if (a[i] == 0) continue;
      int at = -1;
      for (int j = i; j >= 1; j--) if (a[j] == 0) {
        at = j;
        break;
      }
      if (at == -1) break;
      a[at] = a[i];
      a[i] = 0;
    }
    for (int i = 1; i <= n; i++) printf("%d ", a[i] - 1); printf("\n");
  }

  return 0;
}
