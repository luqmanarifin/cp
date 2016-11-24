#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int len = 1e9;
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    len = min(len, r - l + 1);
  }
  printf("%d\n", len);
  for (int i = 0; i < n; i++) printf("%d ", i % len);

  return 0;
}
