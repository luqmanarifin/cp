#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 2e9;

int a[N], n;

int get(int l, int r) {
  if (l > r) return 0;
  return upper_bound(a, a + n, r) - lower_bound(a, a + n, l); 
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) {
      int v = (abs(a[i]) + 1) / 2;
      ans += get(a[i] + 1, -v);
      ans += get(v, 2 * abs(a[i]));
    } else if (a[i] > 0) {
      ans += get(a[i] + 1, a[i] * 2);
    }
  }
  cout << ans << endl;
  return 0;
}
