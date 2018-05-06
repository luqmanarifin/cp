
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  a[0] = 1;
  a[n + 1] = 1e6;
  int ans = 1e9;
  for (int i = 0; i <= n; i++) {
    ans = min(ans, max(a[i] - a[0], a[n + 1] - a[i + 1]));
  }
  cout << ans << endl;
  return 0;
}
