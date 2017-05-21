#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) tmp = tmp * a % mod;
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long solve(int N, int L) {
  if (N == 1) return L;
  return N * (power(N, L) - 1 + mod) % mod * inv(N - 1) % mod;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  while (a && b) {
    printf("%lld\n", solve(a, b));
    scanf("%d %d", &a, &b);
  }
  return 0;
}
