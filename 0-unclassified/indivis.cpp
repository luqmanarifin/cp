#include <bits/stdc++.h>

using namespace std;

long long kpk(long long a, long long b) {
  return a / __gcd(a, b) * b;
}

int a[] = {2, 3, 5, 7};

int main() {
  long long n;
  scanf("%I64d", &n);
  long long ans = 0;
  for(int mask = 0; mask < (1 << 4); mask++) {
    long long now = 1;
    for(int i = 0; i < 4; i++) {
      if(mask & (1 << i)) {
        now *= a[i];
      }
    }
    if(__builtin_popcount(mask) % 2) {
      ans -= n / now;
    } else {
      ans += n / now;
    }
  }
  cout << ans << endl;
  return 0;
}