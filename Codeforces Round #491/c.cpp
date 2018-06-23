#include <bits/stdc++.h>

using namespace std;

long long eat(long long n, long long k) {
  if (n <= k) return n;
  n -= k;
  return k + eat(n - n / 10, k);
}

int main() {
  long long n;
  cin >> n;
  long long l = 1, r = n;
  while (l < r) {
    long long mid = (l + r) >> 1;
    long long got = eat(n, mid);
    if (got * 2 >= n) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}
