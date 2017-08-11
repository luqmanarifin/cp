#include <bits/stdc++.h>

using namespace std;

const int N = 6e5 + 5;
const long long mod = 1e9 + 9;

long long fact[N], ifact[N];

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
  if (n < 0 || k < 0 || n < k) return 0;
  return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

long long sum(int l, int r) {
  return c(l + r, l);
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
    int N, M, L, R;
    scanf("%d %d %d %d", &N, &M, &L, &R);
    int l = N - M + 1;
    int r = M;
    long long ans = sum(l + L - 1, r + R - 1);
    ans -= sum(l - 1, r + R - 1);
    ans -= sum(l + L - 1, r - 1);
    ans += sum(l - 1, r - 1);
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }    
  return 0;
}
