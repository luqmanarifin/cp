// kadalbonek
#include <bits/stdc++.h>

using namespace std;

long long a, b, p;

double f(long long n) {
  return a * cbrt(n) + b * sqrt(n);
}

int main() {
  scanf("%I64d %I64d %I64d", &a, &b, &p);
  long long l = 1, r = 1e18;
  while(l < r) {
    long long mid = (l + r) >> 1;
    if(f(mid) < p) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  cout << l << endl;
  return 0;
}
