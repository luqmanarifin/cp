#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) a[i] += a[i - 1];
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    int cur = a[r] - a[l - 1];
    if (cur >= 0) ans += cur;
  }
  cout << ans << endl;
  return 0;
}
