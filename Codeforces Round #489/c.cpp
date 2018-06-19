#include <bits/stdc++.h>
using namespace std;

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

long long mul(long long a, long long b) {
  return a * b % mod;
}

long long sub(long long a, long long b) {
  long long ret = a - b;
  if (ret < 0) ret += mod;
  return ret;
}

int main() {
  long long x, k;
  cin >> x >> k;
  if (x == 0) {
    puts("0");
    return 0;
  }
  x = mul(x, 2);
  cout << sub(mul(power(2, k), x), sub(power(2, k), 1)) << endl;
  return 0;
}
