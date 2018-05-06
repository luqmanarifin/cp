
#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
const int N = 5005;

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

long long comb(int n, int k) {
  if (n < 0 || k < 0 || n < k) return 0;
  return fact[n] * ifact[k] % mod * ifact[n-k] % mod;
}

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }

  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  
  long long ab = 1;
  for (int i = 1; i <= min(a, b); i++) {
    ab += comb(a, i) * comb(b, i) % mod * fact[i];
    ab %= mod;
  } 

  long long bc = 1;
  for (int i = 1; i <= min(b, c); i++) {
    bc += comb(b, i) * comb(c, i) % mod * fact[i];
    bc %= mod;
  }

  long long ac = 1;
  for (int i = 1; i <= min(a, c); i++) {
    ac += comb(a, i) * comb(c, i) % mod * fact[i];
    ac %= mod;
  }


  cout << ab * bc % mod * ac % mod << endl;
  return 0;
}
