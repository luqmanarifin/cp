#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    sort(a, a + n);
    long long ans = a[0], add = a[0];
    for (int i = 1; i < n; i++) {
      long long now = a[i] - add;
      ans = max(ans, now);
      add += now;
      // printf("%d: %lld\n", i, now);
    }
    printf("%lld\n", ans);
  }

  return 0;
}
