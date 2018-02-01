#include <bits/stdc++.h>

using namespace std;

int main() {
  while (1) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (n == 0 && k == 0) break;
    long long ans = 1;
    k = min(k, n - k);
    for (int i = 1; i <= k; i++) {
      ans = ans * (n - i + 1) / i;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
