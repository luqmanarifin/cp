#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("powers.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    int g, nim = 0;
    scanf("%d", &g);
    while (g--) {
      int b, n;
      scanf("%d %d", &b, &n);
      int v;
      if (b % 2) {
        v = n % 2;
      } else {
        n %= b + 1;
        v = (n == b? 2 : n % 2);
      }
      nim ^= v;
    }
    puts(nim? "1" : "2");
  }

  return 0;
}
