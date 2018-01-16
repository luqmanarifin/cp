#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    for (int i = 0; i < n; i++) if ((i & x) == i) a[i] -= y;
    int ans = 0;
    for (int i = 0; i < n; i++) if (a[i] > 0) ans++;
    printf("%d\n", ans);
  }
  return 0;
}
