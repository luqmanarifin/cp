#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 2e4 + 5;

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

void init() {
  fact[0] = ifact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
}

int main() {
  init();
  int t;
  scanf("%d", &t);
  while(t--) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", (int) c(a + b, a));
  }
  return 0;
}
