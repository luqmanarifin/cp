#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int mod = 1e9 + 7;

long long fact[N], ifact[N];
long long ans[N], p[N];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long temp = power(a, b / 2);
  temp = temp * temp % mod;
  if (b & 1) {
    temp = temp * a % mod;
  }
  return temp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long c(int n, int k) {
  if (n < k || k < 0 || n < 0) return 0;
  return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(p, 0, sizeof(p));
    memset(ans, 0, sizeof(ans));
    
    int m, n;
    scanf("%d %d", &m, &n);
    long long now = 1;
    for (int i = n - 1; i <= m; i++) {
      p[i] = c(i, n - 1) * now % mod;
      now = now * (n - 1) % mod;
    }
    for (int i = 1; i < N; i++) {
      ans[i] = ans[i - 1] * n % mod + p[i - 1];
      ans[i] %= mod;
    }
    printf("%lld\n", ans[m]);
  }
  return 0;
}
