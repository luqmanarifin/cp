#include <bits/stdc++.h>

using namespace std;

const int da[] = {-2, -1, 1, 2, 1, -1};
const int db[] = {0, -2, -2, 0, 2, 2};

int main() {
  long long n;
  cin >> n;
  long long l = 0, r = 580e6;
  while(l < r) {
    long long mid = (l + r + 1) >> 1;
    if(3 * mid * (mid + 1) <= n) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  long long a = 2 * l, b = 0;
  n -= 3 * l * (l + 1);
  if(n) {
    a += da[4];
    b += db[4];
    n--;
  }
  long long del = min(l, n);
  n -= del;
  a += da[5] * del;
  b += db[5] * del;
  for(int i = 0; i < 6; i++) {
    del = min(l + 1, n);
    n -= del;
    a += da[i] * del;
    b += db[i] * del;
  }
  printf("%I64d %I64d\n", a, b);
  return 0;
}
