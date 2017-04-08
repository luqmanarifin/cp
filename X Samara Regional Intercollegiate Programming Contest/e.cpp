#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long inf = 1e18;

long long a[N], b[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%I64d", a + i);
  for (int i = 0; i < m; i++) scanf("%I64d", b + i);
  a[0] = -inf;
  a[n + 1] = inf;
  
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    int p = upper_bound(a, a + n + 1, b[i]) - a - 1;
    int q = p + 1;
    int j = i;
    while (j + 1 < m && b[j + 1] <= a[q]) j++;
    long long cur = a[q] - a[p];
    cur = min(cur, 2 * (a[q] - b[i]));
    cur = min(cur, 2 * (b[j] - a[p]));
    for (int k = i; k < j; k++) {
      cur = min(cur, 2 * (b[k] - a[p]) + 2 * (a[q] - b[k+1]));
    }
    ans += cur;
    //printf("%d %d\n", i, j);
    i = j;
  }
  cout << ans << endl;
  return 0;
}
