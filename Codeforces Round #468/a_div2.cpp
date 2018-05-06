
#include <bits/stdc++.h>

using namespace std;

int sum(int n) {
  return n * (n + 1) / 2;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int d = abs(a - b);
  printf("%d\n", sum(d / 2) + sum(d / 2 + d % 2));
  return 0;
}
