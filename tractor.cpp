#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int ans = 0;
    for(int i = 0; (1 << i) - 1 <= n + m; i++) {
      int tot = (1 << i) - 1;
      int l = min(n, tot);
      int r = min(m, tot);
      r = tot - r;
      ans += max(l, r) - min(l, r) + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
