
#include <bits/stdc++.h>

using namespace std;

int a[10];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= 8; i++) a[i - 1] = i;
  do { 
    if (n == 0) break;
    int l = a[0] * 10 + a[1];
    int r = a[2] * 10 + a[3];
    int h = a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[7];
    if (l * r == h) {
      printf("%d%dx%d%d=%d%d%d%d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
      n--;
    }
  } while (next_permutation(a, a + 8));
  return 0;
}
