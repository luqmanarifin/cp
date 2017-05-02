#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const long long mod = 1e9 + 7;

long long fact[N], ifact[N];
char s[N];

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
  return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') a++;
      else if (s[i] == 'b') b++;
      else if (s[i] == 'c') c++;
      else d++;
    }
    long long first = 0;
    for (int i = 1; i <= min(a, b); i++) {
      first += comb(a, i) * comb(b, i);
      first %= mod;
    }
    long long second = 0;
    for (int i = 1; i <= min(c, d); i++) {
      second += comb(c, i) * comb(d, i);
      second %= mod;
    }
    long long ans = first * second + first + second;
    cout << ans % mod << endl;
  }
  return 0;
}
