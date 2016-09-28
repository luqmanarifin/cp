#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (n == 1) {
      printf("%d\n", 1);
      continue;
    }
    printf("1 1");
    int a = 1, b = 1;
    for (int i = 0; i < n - 2; i++) {
      int c = a + b;
      printf(" %d", c);
      a = b;
      b = c;
    }
    printf("\n");
  }

  return 0;
}
