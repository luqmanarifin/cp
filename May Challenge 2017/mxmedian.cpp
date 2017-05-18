#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], ans[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) scanf("%d", a + i);
    sort(a, a + 2 * n);
    printf("%d\n", a[n + n/2]);
    for (int i = 0; i < 2 * n; i++) {
      int t = i % n;
      if (i < n) {
        ans[2 * t] = a[i];
      } else {
        ans[2 * t + 1] = a[i];
      }
    }
    for (int i = 0; i < 2 * n; i++) printf("%d ", ans[i]); printf("\n");
  }

  return 0;
}
