
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 5;

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

long long inv(long long a) {
  return power(a, mod - 2);
}

long long c(int n, int k) {
  if (n < k || n < 0 || k < 0) return 0;
  long long tmp = fact[n] * ifact[k] % mod;
  tmp = tmp * ifact[n - k] % mod;
  return tmp;
}

int main() {
  freopen("galactic.in", "r", stdin);
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (n < k) {
      puts("0");
      continue;
    }
    long long ans = c(n, k) * fact[k] % mod;
    printf("%I64d\n", ans);
  }

  return 0;
}
