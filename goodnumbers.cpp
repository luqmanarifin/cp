#include <bits/stdc++.h>

using namespace std;

const long long inf = 2e18;

long long p, q;

long long mul(long long a, long long b) {
  if(a > inf / b) return inf;
  return a * b;
}

long long gcd(long long a, long long b) {
  return b? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
  return mul(a / gcd(a, b), b);
}

long long solve(long long til) {
  long long ret = 0;
  long long qnow = 1;
  for(int i = 0; qnow <= til; qnow = mul(qnow, q), i++) {
    long long pnow = 1;
    for(int j = 0; j < i + 1; j++) {
      pnow = mul(pnow, p);
    }
    for(; pnow <= til; pnow = mul(pnow, p)) {
      ret += til / lcm(pnow, qnow);
      ret -= til / lcm(mul(pnow, p), qnow);
      ret -= til / lcm(pnow, mul(qnow, q));
      ret += til / lcm(mul(pnow, p), mul(qnow, q));
    }
  }
  return ret;
}

int main() {
  long long l, r;
  scanf("%I64d %I64d %I64d %I64d", &l, &r, &p, &q);
  cout << solve(r) - solve(l - 1) << endl;
  return 0;
}
