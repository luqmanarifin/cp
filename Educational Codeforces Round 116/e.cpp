#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353LL;

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long ret = power(a, b / 2);
  ret = ret * ret % mod;
  if (b & 1) {
    ret = ret * a % mod;
  }
  return ret;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long ans = power(k, n);
  for (int x = n; x <= k; x++) {
    long long cur = n * power(x - 1, n - 1) % mod;
    ans -= cur;
    if (ans < 0) ans += mod;
  }
  cout << ans << endl;
  return 0;
}
