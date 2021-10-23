#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long x, k;
    scanf("%lld %lld", &x, &k);
    printf("%lld %lld\n", 2 * x, x * k * (x * k - 1));
  }

  return 0;
}
