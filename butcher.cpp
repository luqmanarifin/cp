#include <bits/stdc++.h>

using namespace std;

long long mod;

long long power(long long a, long long b) {
  if(b == 0) {
    return 1;
  }
  long long temp = power(a, b / 2);
  temp *= temp;
  temp %= mod;
  if(b & 1) {
    temp *= a;
    temp %= mod;
  }
  return temp;
}

int main() {
  long long a, k1, k2;
  scanf("%lld %lld %lld %lld", &a, &mod, &k1, &k2);
  a *= power(10, k1 - 1);
  a %= mod;
  int show = k2 - k1 + 1;
  while(show--) {
    printf("%lld", a * 10 / mod);
    a = a * 10 % mod;
  }
  printf("\n");
  return 0;
}
