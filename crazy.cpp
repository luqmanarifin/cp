#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long a, b, n;
    scanf("%lld %lld %lld", &a, &b, &n);
    n--;
    if(n % 6 == 0) {
      printf("%lld\n", (a + 4*mod) %mod);
    } else if(n % 6 == 1) {
      printf("%lld\n", (b + 4*mod) % mod);
    } else if(n % 6 == 2) {
      printf("%lld\n", (b - a + 4*mod) % mod);
    } else if(n % 6 == 3) {
      printf("%lld\n", (-a + 4*mod) % mod);
    } else if(n % 6 == 4) {
      printf("%lld\n", (-b + 4*mod) % mod);
    } else if(n % 6 == 5) {
      printf("%lld\n", (-b + a + 4*mod) % mod);
    } else {
      assert(0);
    }
  }
  
  return 0;
}
