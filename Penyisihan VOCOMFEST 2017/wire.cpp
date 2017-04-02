#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const double eps = 1e-9;

double equal(double a, double b) {
  return abs(a - b) < eps;
}

double cmp(double a, double b) {
  return equal(a, b) || a < b;
}

int a[N], n, u, v;

bool can(long long t) {
  if (u == v) return 1;
  double slope = (double) (a[v] - t) / (abs(u - v));
  if (u < v) {
    for (int i = u + 1; i < v; i++) {
      double lef = t + abs(i - u) * slope;
      double rig = a[i];
      if (cmp(lef, rig)) {
        return 0;
      }
    }
  } else {
    for (int i = u - 1; i > v; i--) {
      double lef = t + abs(i - u) * slope;
      double rig = a[i];
      if (cmp(lef, rig)) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%d %d %d", &n, &u, &v);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    
    long long l = 0, r = 1e14 + 5;
    
    while (l < r) {
      long long mid = (l + r) >> 1;
      if (can(a[u] + mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    
    printf("Case #%d: %lld\n", tt, l);
  }
  return 0;
}