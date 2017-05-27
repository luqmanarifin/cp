#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 9;
const int N = 1e5 + 5;

long long fact[N], ifact[N];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long temp = power(a, b / 2);
  temp = temp * temp % mod;
  if (b & 1) temp = temp * a % mod;
  return temp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long c(int n, int k) {
  return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

long long solve(int n, int k) {
  long long ret = 0;
  for (int i = 0; i <= n; i += k) ret += c(n, i);
  return ret % mod;
}

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i-1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  for (int k = 1; k <= 3; k++) {
    for (int i = 1; i <= 20; i++) {
      printf("%d %d: %lld\n", k, i, solve(i, k));
    }
  }

  return 0;
}
