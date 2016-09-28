#include <bits/stdc++.h>

using namespace std;

#define LL long long

LL a1, b1, a2, b2;

// x, y, gcd(a, b)
tuple<LL, LL, LL> euclid(LL a, LL b) {
  long long s = 0, old_s = 1;
  long long t = 1, old_t = 0;
  long long r = b, old_r = a;
  while (r) {
    long long quotient = old_r / r;
    tie(old_r, r) = make_pair(r, old_r - quotient * r);
    tie(old_s, s) = make_pair(s, old_s - quotient * s);
    tie(old_t, t) = make_pair(t, old_t - quotient * t);
  }
  return make_tuple(s, t, old_r);
}

long long find(long long t) {
  
}

int main() {
  long long l, r;
  scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &a1, &b1, &a2, &b2, &l, &r);
  cout << find(r) - find(l - 1) << endl;
  return 0;
}
