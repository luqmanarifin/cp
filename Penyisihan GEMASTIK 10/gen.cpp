
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t = 5;
  printf("%d\n", t);
  while (t--) {
    int n = 100000;
    int m = 100000;
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; i++) printf("%d ", i);
    for (int i = 0; i < n; i++) printf("%d ", i);
    for (int i = 0; i < m; i++) printf("%d ", 1000000);
  }

  return 0;
}
