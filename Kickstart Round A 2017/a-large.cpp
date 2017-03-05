#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

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

int main() {
  int t;
  scanf("%d", &t);
  long long per_enam = inv(6);
  long long per_duabelas = inv(12);
  for (int tt = 1; tt <= t; tt++) {
    int n, m;
    scanf("%d %d", &n, &m);
    if (n > m) swap(n, m);
    long long ans = 1LL * n * n % mod;
    ans = ans * (ans - 1) % mod;
    ans = ans * per_duabelas % mod;
    long long d = 1LL * (n - 1) * n % mod * (n + 1) % mod * per_enam % mod;
    ans = ans + d * (m - n) % mod;
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("Case #%d: %I64d\n", tt, ans);
    cerr << tt << " done!" << endl;
  }

  return 0;
}
