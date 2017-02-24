#include <bits/stdc++.h>

using namespace std;

const int N = 5;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  n %= 6;
  for (int i = 0; i < 3; i++) a[i] = i;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      swap(a[0], a[1]);
    } else {
      swap(a[1], a[2]);
    }
  }
  printf("%d\n", a[k]);
  return 0;
}
