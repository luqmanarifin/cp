#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
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
    printf("%d\n", min(odd, even));
  }

  return 0;
}
