
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, T;
int a[N], t[N];

int main() {
  scanf("%d %d", &n, &T);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) scanf("%d", t + i);
  double l = 0, r = 0, mid = 0;
  vector<pair<int, int>> vl, vr;      // power, kuota
  for (int i = 0; i < n; i++) {
    if (T < t[i]) {
      r += 1. * abs(t[i] - T) * a[i];
      vr.emplace_back(abs(t[i] - T), a[i]);
    } else if (T > t[i]) {
      l += 1. * abs(t[i] - T) * a[i];
      vl.emplace_back(abs(t[i] - T), a[i]);
    } else {
      mid += a[i];
    }
  }
  sort(vl.begin(), vl.end());
  sort(vr.begin(), vr.end());
  double totl = min(l, r), totr = min(l, r);
  double ans = mid;
  for (auto it : vl) {
    double del = min(1. * it.second, totl / it.first);
    ans += del;
    totl -= del * it.first;
  }
  for (auto it : vr) {
    double del = min(1. * it.second, totr / it.first);
    ans += del;
    totr -= del * it.first;
  }
  printf("%.15f\n", ans);
  return 0;
}
