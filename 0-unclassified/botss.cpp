#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;
const long long mod = 1e9 + 7;

long long fact[N], ifact[N];

long long power(long long a, long long b) {
  if(b == 0) return 1;
  long long temp = power(a, b / 2);
  temp = temp * temp % mod;
  if(b & 1) {
    temp = temp * a % mod;
  }
  return temp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

int main() {
  fact[0] = ifact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  int n;
  scanf("%d", &n);
  n++;
  long long ans = 2 * fact[2*n - 1] % mod;
  ans = ans * ifact[n] % mod;
  ans = ans * ifact[n - 1] % mod;
  ans--;
  if(ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}
