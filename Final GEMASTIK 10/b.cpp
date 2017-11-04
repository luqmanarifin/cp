#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int ans[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    if (n == 1) {
      if (a == b && b == c && a == c) {
        printf("%d\n", a);
      } else {
        puts("-1");
      }
    } else if (n == 2) {
      int p = 0, q = 0;
      for (int i = 0; i < 31; i++) {
        if ((a & (1 << i)) && (b & (1 << i))) {
          p |= (1 << i);
          q |= (1 << i);
        } else if (b & (1 << i)) {
          q |= (1 << i);
        }
      }
      if ((p & q) == a && (p | q) == b && (p ^ q) == c) {
        printf("%d %d\n", p, q);
      } else {
        puts("-1");
      }
    } else {
      memset(ans, 0, sizeof(ans));
      for (int i = 0; i < n; i++) ans[i] = a;
      ans[1] = b;
      for (int j = 0; j < 31; j++) {
        int on = 0;
        for (int i = 0; i < n; i++) {
          if (ans[i] & (1 << j)) {
            on ^= 1;
          }
        }
        on = (on << j);
        if (on != (c & (1 << j))) {
          ans[2] ^= (1 << j);
        }
      }
      int nor = 0, nand = ans[0], nxor = 0;
      for (int i = 0; i < n; i++) {
        nor |= ans[i];
        nand &= ans[i];
        nxor ^= ans[i];
      }
      if (nand == a && nor == b && nxor == c) {
        for (int i = 0; i < n; i++) {
          if (i) printf(" ");
          printf("%d", ans[i]);
        }
        printf("\n");
      } else {
        puts("-1");
      }
    }
  }

  return 0;
}