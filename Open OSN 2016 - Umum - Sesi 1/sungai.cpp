#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 1e6 + 5;

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
  k = min(k, n - k);
  long long ret = 1;
  for(int i = 0; i < k; i++) {
    ret = ret * (n - i) % mod;
    ret = ret * inv(i + 1) % mod;
  }
  return ret;
}

char s[N], junk[22];

int main() {
  int n, m, k;
  scanf("%s %d %d %d", junk, &n, &m, &k);
  long long ans = c(m, k);
  ans = ans * power(power(2, m), n - 1) % mod;
  cout << ans << endl;
  return 0;
}