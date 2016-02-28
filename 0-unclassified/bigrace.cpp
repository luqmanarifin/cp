#include <bits/stdc++.h>

using namespace std;

long long kpk(long long a, long long b) {
  return a / __gcd(a, b) * b;
}

int main() {
  long long t, w, b;
  cin >> t >> w >> b;
  long long a;
  if(kpk(b, w) < 0) {
    a = 0;
  } else {
    a = t / kpk(b, w);
  }
  cout << a << endl;
  long long x = kpk(b, w) * a;
  long long ans = a * min(b, w) + min(t - x + 1, min(b, w)) - 1;
  long long fpb = __gcd(ans, t);
  cout << ans << ' ' << t << endl;
  ans /= fpb;
  t /= fpb;
  printf("%I64d/%I64d\n", ans, t);
  return 0;
}
