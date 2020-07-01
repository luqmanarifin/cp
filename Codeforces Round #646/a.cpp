#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d %d", &n, &x);
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      if (v % 2) {
        odd++;
      } else {
        even++;
      }
    }
    if (x % 2) {
      if (odd == 0) {
        puts("No");
        continue;
      }
      int maks = (odd % 2? odd : odd - 1) + even;
      puts(maks >= x? "Yes" : "No");
    } else {
      if (odd == 0 || even == 0) {
        puts("No");
        continue;
      }
      int maks = (odd % 2? odd : odd - 1) + even;
      puts(maks >= x? "Yes" : "No");
    }
  }

  return 0;
}
