#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 10005;

long long fact[N], ifact[N];

long long c(int n, int k) {
  if(n < k || n < 0 || k < 0) {
    return 0;
  }
  long long temp = fact[n] * ifact[k];
  temp %= mod;
  temp *= ifact[n - k];
  temp %= mod;
  return temp;
}

long long power(long long a, long long b) {
  if(b == 0) return 1;
  long long temp = power(a, b / 2);
  temp *= temp;
  temp %= mod;
  if(b & 1) {
    temp *= a;
    temp %= mod;
  }
  return temp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

// n object ditaruh di k tempat
long long stars(int n, int k) {
  return c(n + k - 1, n);
}

int main() {
  fact[0] = ifact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
    ifact[i] = inv(fact[i]);
  }

  int n;
  scanf("%d", &n);
  long long ans = 1;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    ans *= stars(a - 1, sum + 1);
    ans %= mod;
    sum += a;
  }
  cout << ans << endl;
  return 0;
}
