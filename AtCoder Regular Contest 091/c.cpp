
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, m;
  scanf("%lld %lld", &n, &m);
  if (n > m) swap(n, m);
  long long ans = 0;
  if (n == 1) {
    if (m == 1) {
      ans = 1;
    } else if (m == 2) {
      ans = 0;
    } else {
      ans = m - 2;
    }
  } else if (n == 2) {
    ans = 0;
  } else {
    ans = (n - 2) * (m - 2);
  }
  cout << ans << endl;
  return 0;
}
