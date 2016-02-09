#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return b? gcd(b, a % b): a;
}

pair<long long, long long> reduce(long long a, long long b) {
  long long g = gcd(a, b);
  return {a / g, b / g};
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long g = gcd(a * d, b * c);
    pair<long long, long long> fpb = reduce(g, b * d);
    pair<long long, long long> kpk = reduce(a * c, g);
    printf("%lld/%lld %lld/%lld\n", fpb.first, fpb.second, kpk.first, kpk.second);
  }
  
  return 0;
}
