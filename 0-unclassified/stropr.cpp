#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

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

long long a[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n, k, m;
    scanf("%lld %lld %lld", &n, &k, &m);
    for(int i = 1; i <= n; i++) {
      scanf("%lld", a + i);
      a[i] %= mod;
    }
    long long ans = 0, now = 1;
    int cnt = 0;
    for(int j = k; j >= 1; j--) {
      ans += a[j] * now;
      ans %= mod;
      cnt++;
      now *= ((m + cnt - 1) % mod);
      now %= mod;
      now *= inv(cnt);
      now %= mod;
    }
    printf("%lld\n", ans);
  }
  
  return 0;
}