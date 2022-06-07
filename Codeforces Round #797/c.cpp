#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N], c[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) scanf("%d", b + i);
    int last = 0;
    for (int i = 0; i < n; i++) {
      last = max(last, a[i]);
      c[i] = b[i] - last;
      last = max(last, b[i]);
    }
    for (int i = 0; i < n; i++) printf("%d%c", c[i], i == n - 1? '\n' : ' ');
  }

  return 0;
}
