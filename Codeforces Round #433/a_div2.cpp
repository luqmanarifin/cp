#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = (n - 1) / 2; i >= 1; i--) {
    int j = n - i;
    if (__gcd(i, j) == 1) {
      printf("%d %d\n", i, j);
      return 0;
    }
  }
  return 0;
}