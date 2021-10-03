#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    int full = x / (a[n-1] + a[n-2]);
    x -= full * (a[n-1] + a[n-2]);
    int ans = 2 * full + (x == 0? 0 : (x <= a[n-1]? 1 : 2));
    printf("%d\n", ans);
  }
  return 0;
}
