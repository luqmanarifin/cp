#include <bits/stdc++.h>

using namespace std;

const long long lim = 1000000000000000000LL;

long long add(long long a, long long b, long long mod) {
  return (a + b) % mod;
}

long long mul(long long a, long long b, long long mod) {
  a %= mod; b %= mod;
  if(a == 0 || b == 0) return 0;
  long long base = lim / a;
  if(base < b) {
    base++;
    return add(mul(a * base % mod, b / base, mod), mul(a, b % base, mod), mod); 
  } else {
    return a * b % mod;
  }
}

long long power(long long a, long long b, long long mod) {
  if(b == 0) return 1 % mod;
  long long temp = power(a, b / 2, mod);
  temp = mul(temp, temp, mod);
  if(b & 1) {
    temp = mul(temp, a, mod);
  }
  return temp;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    puts(power(a, 64, b)? "No" : "Yes");
  }
  
  return 0;
}
