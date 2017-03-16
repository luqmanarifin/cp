#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;
const int mod = 1e9 + 7;

char s[N];
int l[N], r[N];

long long fact[N], ifact[N];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long temp = power(a, b / 2);
  temp = temp * temp % mod;
  if (b & 1) {
    temp = temp * a % mod;
  }
  return temp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long c(int n, int k) {
  if (n < 0 || k < 0 || n < k) return 0;
  return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

long long calc(int n, int m) {
  return c(n + m, n + 1);
}

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  for (int i = 1; i <= len; i++) {
    l[i] = l[i - 1] + (s[i] == '(');
  }
  for (int i = len; i >= 1; i--) {
    r[i] = r[i + 1] + (s[i] == ')');
  }
  long long ans = 0;
  for (int i = 1; i <= len; i++) {
    if (s[i] == ')') continue;
    int n = l[i] - 1;
    int m = r[i];
    //printf("%d %d %I64d\n", n, m, calc(n, m));
    ans += calc(n, m);
  }
  cout << ans % mod << endl;
  
  return 0;
}
