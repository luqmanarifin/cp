#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 1e5 + 5;

long long fact[N], ifact[N];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

long long c(int n, int k) {
  return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i-1] * i % mod;
    ifact[i] = power(fact[i], mod - 2);
  }

  int n, k;
  scanf("%d %d", &n, &k);
  k = min(k, n);
  long long ans = 0;
  for (int i = 0; i <= k; i++) {
    ans += c(n, i);
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
