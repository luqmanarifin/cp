#include <bits/stdc++.h>

using namespace std;

long long sum(int n, int a, int an) {
  return 1LL * n * (a + an) / 2;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    long long ans = sum(m, 1, m) + sum(n - 1, 2 * m, 1LL * n * m);
    printf("%lld\n", ans);
  }

  return 0;
}
