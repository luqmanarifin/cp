#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

long long fact[N], ifact[N];

long long power(long long a, long long b) {
  if(b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if(b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long c(int n, int k) {
  return (fact[n] * ifact[k] % mod) * ifact[n - k] % mod;
}

long long stars(int n, int k) {
  return c(n + k - 1, n);
}

void init() {
  fact[0] = ifact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
}

int main() {
  int rr, rb, bb, br;
  scanf("%d %d %d %d", &rr, &rb, &bb, &br);
  if(rb == 0 && br == 0) {
    if(rr == 0 && bb == 0) {
      puts("2");
    } else if(rr == 0 || bb == 0) {
      puts("1");
    } else {
      puts("0");
    }
    return 0;
  }
  
  init();
  long long ans = 0;
  if(rb == br || rb == br + 1) {
    ans += stars(rr, br + 1) * stars(bb, rb);
  }
  if(rb == br || rb + 1 == br) {
    ans += stars(rr, br) * stars(bb, rb + 1);
  }
  cout << ans % mod << endl;
  return 0;
}
