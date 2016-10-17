#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  for (int i = 1; i < n; i++) a[i] += a[i - 1];
  long long ans = a[n - 1];
  for (int i = n - 2; i >= 1; i--) ans = max(ans, a[i] - ans);
  cout << ans << endl;
  return 0;
}
