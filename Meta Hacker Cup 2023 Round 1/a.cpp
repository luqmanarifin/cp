#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    int ans = 2e9 + 10;
    if (n == 5) {
      int lef = a[4] + a[3] - a[2] - a[0];
      int rig = a[4] + a[2] - a[1] - a[0];
      ans = max(lef, rig);
    } else {
      ans = a[n-1] + a[n-2] - a[1] - a[0];
    }
    printf("Case #%d: %d", tt, ans/2);
    if (ans % 2) printf(".5");
    printf("\n");
  }

  return 0;
}
