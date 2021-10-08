#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long ret = power(a, b / 2);
  ret = ret * ret % mod;
  if (b & 1) ret = ret * a % mod;
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long ans = 0;
    for (int i = 0; i < 40; i++) {
      if (k & (1LL << i)) {
        ans += power(n, i);
        ans %= mod;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
