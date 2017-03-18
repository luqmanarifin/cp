#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  long long l = 1, r = 1e6;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (mid * (mid + 1) / 2 < n) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  cout << l << endl;
  return 0;
}
