#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;

const int N = 1e5 + 5;

long long fact[N], ifact[N], d[N];
int t, n, x;

long long power(int a, int b) {
  if(b == 0) return 1;
  long long temp = power(a, b / 2);
  temp = temp * temp % mod;
  if(b & 1) {
    temp = temp * a % mod;
  }
  return temp;
}

long long c(int a, int b) {
  long long temp = fact[a] * ifact[a - b] % mod;
  temp = temp * ifact[b] % mod;
  return temp;
}

long long full(int k) {
  long long temp = c(n, k);
  temp = temp * temp % mod;
  return temp * fact[k] % mod;
}

long long get(int k) {
  return fact[k] * d[k] % mod;
}

int main() {
  fact[0] = ifact[0] = d[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = power(fact[i], mod - 2);
    d[i] = (i * d[i - 1] + (i % 2? -1 : 1) + mod) % mod;
  }
  
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &n, &x);
    long long ans = 0;
    for(int i = x; i <= n; i++) {
      ans += full(i) * get(n - i);
      ans %= mod;
    }
    cout << ans << endl;
  }
  
  return 0;
}
