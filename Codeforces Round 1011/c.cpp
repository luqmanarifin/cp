#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    if (x == y) {
      puts("-1");
      continue;
    }
    if (x > y) swap(x, y);
    int p = __builtin_clzll(y) ^ 63;
    long long to = (1LL << (p + 1));
    printf("%lld\n", to - y);
  }

  return 0;
}
