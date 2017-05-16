#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];
int ans[N];
pair<int, int> p[N];

int main() {
  int n, w;
  scanf("%d %d", &n, &w);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    p[i] = {a[i], i};
  }
  int need = 0;
  for (int i = 0; i < n; i++) {
    ans[i] = (a[i] + 1) / 2;
    need += ans[i];
  }
  if (w < need) {
    puts("-1");
    return 0;
  }
  w -= need;
  sort(p, p + n);
  reverse(p, p + n);
  int last = -1, lim = 1e9;
  for (int i = 0; i < n; i++) {
    int at = p[i].second;
    if (last != a[at]) {
      lim = min(lim - 1, a[at]);
      last = a[at];
    } else {
      lim = min(lim, a[at]);
    }
    int del = min(w, max(0, lim - ans[at]));
    ans[at] += del;
    w -= del;
  }
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);

  return 0;
}
