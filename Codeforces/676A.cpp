#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  int po = -1, pn = n;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (a[i] == 1) po = i;
    if (a[i] == n) pn = i;
  }
  int l = min(po, pn);
  int r = max(po, pn);
  int ans = max(n - 1 - l, r);
  cout << ans << endl;
  return 0;
}
