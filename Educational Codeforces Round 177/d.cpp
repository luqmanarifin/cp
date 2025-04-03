#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const long long mod = 998244353;
const int C = 26;

long long fact[N], ifact[N];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long temp = power(a, b / 2);
  temp = temp * temp % mod;
  if (b & 1) temp = temp * a % mod;
  return temp;
}

long long comb(int n, int k) {
  if (n < 0 || k < 0 || n < k) return 0;
  return fact[n] * ifact[n - k] % mod * ifact[k] % mod;
}

long long inv(long long x) {
  return power(x, mod - 2);
}

void add(long long& x, long long b) {
  x += b;
  x %= mod;
}

int a[C];
long long dp[N], ne[N];

int main() {
  fact[0] = 1;
  ifact[0] = inv(1);
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int sum = 0;
    for (int i = 0; i < C; i++) {
      scanf("%d", a + i);
      sum += a[i];
    }
    for (int i = 0; i <= sum / 2; i++) dp[i] = 0;
    dp[0] = 1;

    int cur = 0;
    for (int c = 0; c < C; c++) {
      if (a[c] == 0) continue;
      cur += a[c];
      for (int i = 0; i <= sum / 2; i++) ne[i] = 0;

      for (int i = 0; i <= sum / 2; i++) {
        {
          // put to odd
          int slot_odd = (sum + 1) / 2;
          int next_odd = cur - i;
          if (next_odd >= a[c]) {
            int used_odd = next_odd - a[c];
            add(ne[i], dp[i] * comb(slot_odd - used_odd, a[c]));
          }
        }
        {
          // put to even
          int slot_ev = sum / 2;
          int next_ev = i;
          if (next_ev >= a[c]) {
            int used_ev = next_ev - a[c];
            add(ne[i], dp[i-a[c]] * comb(slot_ev - used_ev, a[c]));
          }
        }
      }

      for (int i = 0; i <= sum / 2; i++) dp[i] = ne[i];
    }
    printf("%lld\n", dp[sum / 2]);
  }


  return 0;
}
