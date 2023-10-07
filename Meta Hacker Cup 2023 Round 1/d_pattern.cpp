#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

int main() {
  long long n = 3;
  for (int i = 0; i < 10; i++) {
    printf("%lld\n", n);
    n = (n * (mod - 1)) % mod;
  }

  return 0;
}
