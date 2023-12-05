#include <bits/stdc++.h>

using namespace std;

void normal(int x) {
  while (x--) {
    printf("()");
  }
}

void bulat(int x) {
  for (int i = 0; i < x; i++) printf("(");
  for (int i = 0; i < x; i++) printf(")");
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (k < n / 2 || k == n) {
    puts("-1");
    return 0;
  }
  int half = n / 2, lef = 0, rig = 0;
  for (int i = n / 2; i < n; i++) {
    if (i == k) {
      normal(lef);
      bulat(half - lef - rig);
      normal(rig);
      break;
    }
    if (lef + 1 > half - (lef + 1)) {
      rig++;
    } else {
      lef++;
    }
  }
  printf("\n");
  return 0;
}
