#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + m);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int cur = 1e9;
    int at = lower_bound(a, a + m, i) - a;
    cur = min(cur, abs(a[at] - i));
    if(at > 0) {
      cur = min(cur, abs(a[at - 1] - i));
    }
    ans = max(ans, cur);
  }
  printf("%d\n", ans);
  return 0;
}
