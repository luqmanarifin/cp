#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int mod = 1e9 + 7;

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

long long c(int n, int k) {
  return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

int main() {
  fact[0] = ifact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m, d, k;
    scanf("%d %d %d %d", &n, &m, &k, &d);
    int ava = 0;
    for(int i = 0; i < n; i++) {
      int num;
      scanf("%d", &num);
      ava += num >= d;
    }
    long long ans = c(ava, k) * c(n - k, m - k) % mod;
    printf("%I64d\n", ans);
  }
  return 0;
}