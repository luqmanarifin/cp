#include <bits/stdc++.h>

using namespace std;

int main() {
  int t = 1;
  printf("%d\n", t);
  while (t--) {
    int n = 100000;
    int a = 1, b = n;
    printf("%d %d %d\n", n, a, b);
    printf("1 ");
    for (int i = 0; i < n - 2; i++) printf("%d ", 1000000000);
    printf("1\n");
  }
  return 0;
}
