#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    bool found = 0;
    for (int i = 0; i < (1 << 20); i++) {
      int j = c ^ i;
      if ((i & j) == a && (i | j) == b) {
        printf("%d %d\n", i, j);
        found = 1;
        break;
      } 
    }
    if (!found) puts("-1");
  }

  return 0;
}