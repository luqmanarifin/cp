#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N], b[N], c[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; i++) {
    b[i] = b[i - 1];
    if (a[i] == 0) {
      b[i]++;
    }
  }
  for (int i = n; i >= 1; i--) {
    c[i] = c[i + 1];
    if (a[i]) {
      c[i]++;
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, b[i] + c[i + 1]);
  }
  cout << ans << endl;
  return 0;
}
