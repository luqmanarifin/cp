#include <bits/stdc++.h>

using namespace std;

void normal(int x) {
  while (x--) {
    printf("()");
  }
}

void in(int x) {
  printf("(");
  normal(x);
  printf(")");
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
  if (k == n - 1) {
    normal(n / 2);
  } else {
    int half = n / 2;
    int first = half / 2;
    int second = half - first - 1;
    // printf("%d -- %d\n", k, n - 1 - second);
    if (n >= 10 && k > n - 1 - second) {
      first += (n - 2 - k);
      second = half - first - 1;
      normal(first);
      in(second);
    } else {
      first = k - half;
      second = half - first;
      normal(first);
      bulat(second);
    }
  }
  printf("\n");
  return 0;
}
