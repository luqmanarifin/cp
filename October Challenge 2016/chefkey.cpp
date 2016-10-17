#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, c;
    scanf("%d %d %d", &n, &m, &c);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      if (c % i) continue;
      int j = c / i;
      ans += (m / j > 0? 1 : 0);
    }
    printf("%lld\n", ans);
  }

  return 0;
}
