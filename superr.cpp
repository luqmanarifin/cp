#include <bits/stdc++.h>

using namespace std;

int lcm(int a, int b) {
  return a / __gcd(a, b) * b;
}

int lcm(int a, int b, int c, int d, int e) {
  return lcm(a, lcm(b, lcm(c, lcm(d, e))));
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    printf("Case #%d: %d\n", tt, lcm(a, b, c, d, e) + 2000);
  }
  
  return 0;
}
