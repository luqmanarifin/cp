
#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const long long mod = 1e9 + 7;

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

int n;
long long a[N];
long long s[N], sv[N];

long long find(int l, int r) {
  return s[r] * sv[l-1] % mod;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) scanf("%lld", a + i);
  s[0] = 1;
  for (int i = 1; i < n; i++) s[i] = s[i - 1] * a[i] % mod;
  for (int i = 0; i < n; i++) sv[i] = inv(s[i]);


  return 0;
}
