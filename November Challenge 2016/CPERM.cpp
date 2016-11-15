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

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    if (n < 3) {
      puts("0");
    } else {
      long long ans = power(2, n - 1) - 2;
      ans %= mod;
      if (ans < 0) ans += mod;
      cout << ans << endl;
    }
  }

  return 0;
}
