#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const int offset = 5000;
const long long mod = 998244353;

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
  if (n < 0 || k < 0 || n < k) return 0;
  return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

long long take(int ball, int basket) {
  return c(ball + basket - 1, basket - 1);
}

int cnt[N], a[N], cur[N];

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }

  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof(cnt));

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      cnt[a[i] + offset]++;
    }
    int top = a[n - 1];
    int down = a[0];

    long long ans = 0;
    for (int sum = down; sum <= top; sum++) {

      for (int i = down; i <= top; i++) cur[i+offset] = 0;
      if (top > 0) {
        for (int i = 1; i <= top; i++) cur[i+offset]++;
      }
      for (int i = max(0, top) - 1; i >= sum; i--) {
        cur[i+offset]++;
      }

      long long now = 1;
      for (int i = max(-1, top); i > min(1, down); i--) {
        if (cur[i+offset] <= cnt[i+offset]) {
          int to_add = cnt[i+offset] - cur[i+offset];
          int basket = cur[i+offset] + (i == 0);
          now = now * take(to_add, basket) % mod;
          cur[i+offset] += to_add;
          cur[i - 1 + offset] += to_add;
        } else {
          now = 0;
          break;
        }
      }
      int d = min(1, down);
      if (cur[d+offset] != cnt[d+offset]) now = 0;
      ans = (ans + now) % mod;
    }
    printf("%lld\n", ans);
  }

  return 0;
}
