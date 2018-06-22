#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N], d[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    if (a[i] <= k) {
      d[i] = 1;
    } else {
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] <= k) {
      d[i] = 1;
    } else {
      break;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += d[i];
  }
  cout << ans << endl;
  return 0;
}
