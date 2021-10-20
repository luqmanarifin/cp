#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int d = 0, e = 0;
    for (int i = 0; i < 5; i++) {
      int v;
      scanf("%d", &v);
      if (v == 1) {
        d++;
      } else if (v == 2) {
        e++;
      }
    }
    if (d == e) {
      puts("DRAW");
    } else if (d > e) {
      puts("INDIA");
    } else {
      puts("ENGLAND");
    }
  }

  return 0;
}
