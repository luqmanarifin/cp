#include <bits/stdc++.h>

using namespace std;

int a[100], p[100];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    long long ans = -1;
    do {
      long long cur = 0;
      for (int i = 1; i < n; i++) {
        cur += a[i - 1] * a[i];
      }
      if (cur > ans) {
        ans = cur;
        for (int i = 0; i < n; i++) p[i] = a[i];
      }
    } while (next_permutation(a, a + n));
    printf("%lld\n", ans);
    for (int i = 0; i < n; i++) printf("%d ", p[i]); printf("\n");
  }
  return 0;
}
