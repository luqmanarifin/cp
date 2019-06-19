#include <bits/stdc++.h>

using namespace std;

int a[3];

int main() {
  for (int i = 0; i < 3; i++) scanf("%d", a + i);
  sort(a, a + 3);
  int k;
  scanf("%d", &k);
  long long ans = 0;
  if (a[1] - a[0] <= k) {
    ans += k - (a[1] - a[0]);
  }
  if (a[2] - a[1] <= k) {
    ans += k - (a[2] - a[1]);
  }
  cout << ans << endl;
  return 0;
}
