#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int n, d, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d",  a + i);
  scanf("%d %d", &d, &m);
  int ans = 0;
  for (int i = 0; i + m <= n; i++) {
    int cur = 0;
    for (int j = 0; j < m; j++) {
      cur += a[i + j];
    }
    if (d == cur) ans++;
  }
  cout << ans << endl;
  return 0;
}
