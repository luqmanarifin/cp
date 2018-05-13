#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

long long a[N];

int main() {
  int n, w;
  scanf("%d %d", &n, &w);
  long long now = 0, mn = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    now += a[i];
    mn = min(mn, now);
    mx = max(mx, now);
  }
  if (mx - mn > w) {
    puts("0");
    return 0;
  }
  long long ans = w - (mx - mn) + 1;
  cout << ans << endl;
  return 0;
}
