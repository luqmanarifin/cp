#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return b? gcd(b, a % b) : a;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    long long f = gcd(c, d);
    long long l = min(a, b);
    long long r = max(a, b);
    long long p = (r - l) / f;
    long long ans = abs(r - (l + p*f));
    ans = min(ans, abs(r - (l + (p+1)*f)));
    printf("%lld\n", ans);
  }
  
  return 0;
}