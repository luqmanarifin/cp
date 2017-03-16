#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, m;
  scanf("%I64d %I64d", &n, &m);
  if (n <= m) {
    cout << n << endl;
  } else {
    n -= m;
    long long l = 0, r = 2e9;
    while (l < r) {
      long long mid = (l + r) >> 1;
      long long tot = mid * (mid + 1) / 2;
      if (tot < n) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    cout << m + l << endl;
  }
  return 0;
}
