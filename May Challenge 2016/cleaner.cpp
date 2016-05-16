#include <bits/stdc++.h>

using namespace std;

const int N = 101;
const long long mod = 1e9 + 7;

bool is[N];
vector<int> p, pk;
int n, lim;

// udah - mask udah
long long dp[20][1 << 15];
long long fact[N], ifact[N];

int get_lsb(int mask) {
  if(mask == 0) return -1;
  int ret = mask & (mask - 1);
  int t = abs(ret - mask);
  return (__builtin_clz(t) ^ 31);
}

int get_msb(int mask) {
  if(mask == 0) return -1;
  return (__builtin_clz(mask) ^ 31);
}

int power(int a, int b) {
  if(b == 0) return 1;
  int temp = power(a, b / 2);
  temp *= temp;
  if(b & 1) {
    temp *= a;
  }
  return temp;
}

long long powmod(long long a, long long b) {
  if(b == 0) return 1;
  long long temp = powmod(a, b / 2);
  temp = temp * temp % mod;
  if(b & 1) {
    temp = temp * a % mod;
  }
  return temp;
}

long long inv(long long a) {
  return powmod(a, mod - 2);
}

long long c(int all, int k) {
  if(all < k || all < 0 || k < 0) return 0;
  return fact[all] * ifact[k] % mod * ifact[all - k] % mod;
}

int main() {
  fact[0] = ifact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      if(i < 50) {
        p.push_back(i);
      } else {
        pk.push_back(i);
      }
      for(int j = i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  int a, b, c;
  while(cin >> a >> b >> c) {
    int cnt = (a != 1 )+ (b != 1) + (c != 1);
    int mask = 0;
    for(int i = 0; i < p.size(); i++) {
      if(a % p[i] == 0 || b % p[i] == 0 || c % p[i] == 0) {
        mask |= (1 << i);
      }
    }
    dp[cnt][mask]++;
  }
  for(int i = 0; i <= 3; i++) {
    for(int j = 0; j < (1 << p.size()); j++) {
      if(dp[i][j]) printf("from %d %d %d\n", i, j, dp[i][j]);
    }
  }
  return 0;
}