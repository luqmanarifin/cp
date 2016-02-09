#include <bits/stdc++.h>

using namespace std;

int main() {
  int m, n;
  scanf("%d %d", &n, &m);
  int ans = -1;
  if(1 <= m - 1 && m + 1 <= n) {
    int l = m - 1;
    int r = n - m;
    if(l >= r) {
      ans = m - 1;
    } else {
      ans = m + 1;
    }
  } else if(m == 1) {
    if(n != 1) ans = m + 1;
    else ans = m;
  } else if(m == n) {
    if(n != 1) ans = m - 1;
    else ans = m;
  } else {
    assert(0);
  }
  cout << ans << endl;
  return 0;
}
