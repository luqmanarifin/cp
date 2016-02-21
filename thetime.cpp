#include <bits/stdc++.h>

using namespace std;

int main() {
  int h, m, a;
  scanf("%d:%d %d", &h, &m, &a);
  int ans = h * 60 + m + a;
  ans %= (24 * 60);
  h = ans / 60;
  m = ans % 60;
  printf("%d%d:%d%d\n", h/10, h%10, m/10, m%10);
  return 0;
}