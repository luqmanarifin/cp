#include <stdio.h>

int main() {
  int *a, i;
  a = malloc(4 * sizeof(int));
  for(i = 0; i < 4; i++) {
    a[i] = i;
    printf("%d ", a[i]);
  }
  return 0;
}
