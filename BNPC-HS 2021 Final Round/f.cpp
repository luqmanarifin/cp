#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int BIT = 20;

int a[N], res[N];

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int j = 0; (1 << j) < n; j++) {
    if (x & (1 << j)) {
      for (int i = 0; i + (1 << j) < n; i++) {
        res[i] = (a[i] ^ a[i + (1 << j)]);
      }
      for (int i = 0; i + (1 << j) < n; i++) {
        a[i] = res[i];
      }
    }
  }
  for (int i = 0; i < n - x; i++) {
    printf("%d%c", a[i], (i == n - x - 1? '\n' : ' '));
  }

  return 0;
}
