#include <bits/stdc++.h>

using namespace std;

int main() {
  int d, l, a, b;
  scanf("%d %d %d %d", &d, &l, &a, &b);
  printf("%.15f\n", (double) (l - d) / (a + b));
  return 0;
}
