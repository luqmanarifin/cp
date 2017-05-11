#include <stdio.h>

int a[105];

int main() {
  int p = 0;
  int v, i;
  for (i = 0; i < 9; i++) {
    scanf("%d", &v);
    a[p++] = v;
  }
  printf("%d\n%d\n%d\n", a[1], a[5], a[7]);
  return 0;
}
