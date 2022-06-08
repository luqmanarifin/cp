#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    int cnt = __builtin_popcount(n);
    if (cnt == 1) {
      for (int i = 0; i < 60; i++) {
        if ((n & (1LL << i)) == 0) {
          printf("%lld\n", (1LL << i) | n);
          break;
        }
      }
    } else {
      for (int i = 0; i < 60; i++) {
        if (n & (1LL << i)) {
          printf("%lld\n", 1LL << i);
          break;
        }
      }
    }
  }

  return 0;
}
