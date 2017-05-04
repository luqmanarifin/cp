#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], ans[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  fill(ans, ans + N, N);
  int last = -N;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) last = i;
    ans[i] = min(ans[i], i - last);
  }
  last = 2 * N;
  for (int i = n; i >= 1; i--) {
    if (a[i] == 0) last = i;
    ans[i] = min(ans[i], last - i);
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
