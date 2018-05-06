
#include <bits/stdc++.h>

using namespace std;

int a[105];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (k % a[i] == 0) {
      ans = min(ans, k / a[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
