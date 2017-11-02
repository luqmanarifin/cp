#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
    }
    long long ans = 0;
    for (int i = 0; i < 20; i++) {
      int mask = 1 << i;
      for (int j = 0, z = -1; j < n; j++) {
        if (mask & a[j]) {
          ans += 1LL * (j - z) * mask;
        }
        else
          z = j;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
  