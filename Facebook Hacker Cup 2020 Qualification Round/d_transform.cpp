#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int c[N];

int main() {
  int t;
  scanf("%d", &t);
  printf("%d\n", t);
  for (int tt = 1; tt <= t; tt++) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d %d %d %d\n", n, m, 1, n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", c + i);
      printf("%d %d\n", i - 1, c[i]);
    }
  }

  return 0;
}
