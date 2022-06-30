#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) {
      int now = 0;
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        now ^= a[j];
      }
      if (now == a[i]) {
        printf("%d\n", a[i]);
        goto DONE;
      }
    }
    DONE:;
  }

  return 0;
}
