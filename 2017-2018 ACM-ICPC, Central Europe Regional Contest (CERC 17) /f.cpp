#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

void fail() {
  puts("-1 -1");
  exit(0);
}

void solve(long long a, long long b) {
  printf("%lld %lld\n", a, b);
  exit(0);
}

long long p, in[N];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % p;
  if (b & 1) {
    tmp = tmp * a % p;
  }
  return tmp;
}

long long inv(long long a) {
  if (in[a] != -1) return in[a];
  return in[a] = power(a, p - 2);
}

int main() {
  memset(in, -1, sizeof(in));
  long long n, r;
  scanf("%lld %lld %lld", &n, &p, &r);
  
  if (p <= 10) {
    if (n >= 2 * p) {
      if (r != 0) {
        fail();
      } else {
        vector<int> ans;
        for (int i = 1; i <= n && ans.size() < 2; i++) {
          if (i % p == 0) continue;
          ans.push_back(i);
        }
        if (ans.size() < 2) fail();
        solve(ans[1], ans[0]);
      }
    } else {
      for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
          long long now = 1;
          for (int k = 1; k <= n; k++) {
            if (k == i) continue;
            now = now * k % p;
            if (k == j) {
              now = now * k % p;
            }
          }
          if (now == r) solve(i, j);
        }
      }
      fail();
    }
  }
  if (n >= 2 * p) {
    if (r != 0) fail();
    solve(2, 1);
  }
  if (n >= p) {
    if (r == 0) solve(2, 1);
    long long sum = 1;
    for (int i = 1; i <= n; i++) {
      if (i % p == 0) continue;
      sum = sum * i % p;
    }
    long long x = r * inv(sum) % p;
    solve(p, x);
  }
  if (r == 0) fail();
  long long sum = 1;
  for (int i = 1; i <= n; i++) sum = sum * i % p;
  long long inv_sum = inv(sum);
  for (int i = n; i >= 2; i--) {
    long long x = r * i % p;
    x = x * inv_sum % p;
    if (x < i && 0 < x) {
      solve(i, x);
    }
  }
  fail();
  return 0;
}
