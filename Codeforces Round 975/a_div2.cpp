#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, mx = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) mx = max(mx, a[i]);
    int c[2];
    c[0] = c[1] = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == mx) c[i % 2]++;
    }
    int ans = mx + (n + 1) / 2 - (n % 2 && c[0] == 0);
    printf("%d\n", ans);
  }

  return 0;
}
