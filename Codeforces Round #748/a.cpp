#include <bits/stdc++.h>

using namespace std;

int a[3];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", a, a + 1, a + 2);
    for (int i = 0; i < 3; i++) {
      int mx = 0;
      for (int j = 0; j < 3; j++) if (i != j) mx = max(mx, a[j]);
      mx++;
      printf("%d%c", max(0, mx - a[i]), i == 2? '\n' : ' ');
    }

  }

  return 0;
}
