#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

double c[N], x[N];
int m, n, r;

bool ok(int i, int j) {
  return (c[i] - x[j]) * (c[i] - x[j]) + 1 <= r * r;
}

int to(int from, int at) {
  if (ok(from, at)) return from;
  int l = -1, r = -1;
  if (c[from] < x[at]) {
    l = from + 1, r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (ok(mid, at)) {
        r = mid;
      } else {
        if (c[mid] < x[at]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }
  } else {
    l = 1, r = from - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (ok(mid, at)) {
        l = mid;
      } else {
        if (c[mid] < x[at]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }
  }
  assert(l == r);
  return l;
}

int main() {
  scanf("%d %d %d", &n, &m, &r);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", c + i);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%lf", x + i);
  }
  int now = 1;
  double ans = 0;
  for (int i = 1; i <= m; i++) {
    int ke = to(now, i);
    ans += abs(c[ke] - c[now]);
    now = ke;
  }
  printf("%.15f\n", ans);
  return 0;
}
