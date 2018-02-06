#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    fill(a, a + N, N);
    while (k--) {
      int v;
      scanf("%d", &v);
      for (int i = 1; i <= n; i++) {
        a[i] = min(a[i], abs(i - v) + 1);
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
    printf("%d\n", ans);
  }
  return 0;
}
