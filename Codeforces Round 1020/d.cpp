#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9 + 1;

int a[N], b[N], lef[N], rig[N], n, m;

bool can(int k) {
  if (lef[m] <= n) return 1;
  // iterate which one to skip
  for (int i = 1; i <= m; i++) {
    int l = 0, r = n + 1;
    if (i + 1 <= m) {
      r = rig[i + 1];
    }
    if (i - 1 >= 1) {
      l = lef[i - 1];
    }
    if (l < r && k >= b[i]) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= m; i++) scanf("%d", b + i);
    int ptr = 1;
    for (int i = 1; i <= m; i++) {
      while (ptr <= n && a[ptr] < b[i]) ptr++;
      lef[i] = ptr;
      if (ptr <= n) ptr++;
    }
    ptr = n;
    for (int i = m; i >= 1; i--) {
      while (ptr >= 1 && a[ptr] < b[i]) ptr--;
      rig[i] = ptr;
      if (ptr >= 1) ptr--;
    }
    int l = 0, r = inf;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (can(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    if (l == inf) l = -1;
    printf("%d\n", l);
  }

  return 0;
}
