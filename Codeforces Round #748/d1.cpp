#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    bool same = 1;
    int mn = 1e9;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      if (i && a[i] != a[i-1]) same = 0;
      mn = min(mn, a[i]);
    }
    if (same) {
      printf("-1\n");
      continue;
    }
    int ans = a[0] - mn;
    for (int i = 0; i < n; i++) {
      int num = a[i] - mn;
      if (num > 0) {
        ans = __gcd(ans, num);
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
