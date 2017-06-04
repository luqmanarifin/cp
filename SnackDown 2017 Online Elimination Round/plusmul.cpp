#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6 + 5, mod = 1e9 + 7;
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    long long cur = 0;
    for (int i = 0; i < n; i++) {
      long long a;
      scanf("%lld", &a);
      cur = (cur + powmod(2, max(0, i-1))) * a % mod;
      ans = (ans + cur * powmod(2, max(0, n-2-i))) % mod;
    }
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
} 