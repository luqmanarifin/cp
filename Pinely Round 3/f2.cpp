#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long mod = 998244353;

int A[N];
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
  if (n < 0 || k < 0 || n < k) return 0;
  return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

long long put(int a, int b, int token) {
  if (token > min(a, b)) return 0;
  return c(b, token) * fact[a] % mod * ifact[a - token] % mod;
}

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = power(fact[i], mod - 2);
  }

  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", A + i);
    int p = 0;
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
      if (A[i] == -1 && i < n) continue;
      if (i == n) {
        if (A[i] == -1) {
          A[i] = n;
        } else if (A[i] != n) {
          ans = 0;
        }
      }
      int token = A[i] - A[p];
      int a = p - A[p];
      int b = i - p;
      long long cur = 0;
      for (int take = 0; take <= min(token, min(a, b)); take++) {
        cur += put(a, b, take) * put(a + b - take, b, token - take) % mod;
        cur %= mod;
      }
      ans *= cur;
      ans %= mod;

      p = i;
    }
    printf("%lld\n", ans);
  }

  return 0;
}
