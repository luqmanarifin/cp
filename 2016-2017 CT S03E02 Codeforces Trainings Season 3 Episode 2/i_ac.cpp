#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 5;

int a[N];

int main() {
  a[1] = 0, a[2] = 1, a[3] = 1, a[4] = 0;
  int len = 4;
  for (int v = 2; v < 10; v++) {
    for (int i = 1; i <= len; i++) a[len + i] = v;
    for (int i = 1; i <= len; i++) a[len + len + i] = a[i];
    len *= 3;
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) printf("%d", a[i]); printf("\n");
  return 0;
}
