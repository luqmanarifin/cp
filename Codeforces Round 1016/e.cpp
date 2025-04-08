#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], n, k;

bool can(int x) {
  vector<bool> done(x, 0);
  int now = 0, group = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < x && !done[a[i]]) {
      done[a[i]] = 1;
      now++;
      if (now == x) {
        group++;
        now = 0;
        done = vector<bool>(x, 0);
      }
    }
  }
  return group >= k;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int l = 0, r = n;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (can(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    printf("%d\n", l);
  }

  return 0;
}
