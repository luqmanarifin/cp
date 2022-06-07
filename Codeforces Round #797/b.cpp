#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) scanf("%d", b + i);
    int p = -1, x = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] > x) {
        x = a[i];
        p = i;
      }
    }
    int d = a[p] - b[p];
    bool ok = (d >= 0);
    for (int i = 0; i < n; i++) {
      int g = a[i] - d;
      if (g < 0) g = 0;
      if (b[i] != g) {
        ok = 0;
      }
    }
    puts(ok? "YES" : "NO");
  }
  return 0;
}
