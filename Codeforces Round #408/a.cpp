#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  int ans = 1e9;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) continue;
    if (a[i] <= k) {
      ans = min(ans, 10 * abs(i - m));
    }
  }
  cout << ans << endl;
  return 0;
}
