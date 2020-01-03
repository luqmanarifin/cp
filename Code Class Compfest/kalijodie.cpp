#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;

int x[N];
int n, k;

double solve(double at) {
  double ret = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] < at) {
      ret += (at - x[i]) * (at - x[i]);
    }
    if (at + k < x[i]) {
      ret += (x[i] - at - k) * (x[i] - at - k);
    }
  }
  return ret;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", x + i);
  double l = 0, r = 20000 - k;
  for (int it = 0; it < 100; it++) {
    double lf = l + (r - l) / 3;
    double rf = r - (r - l) / 3;
    if (solve(lf) < solve(rf)) {
      r = rf;
    } else {
      l = lf;
    }
  }
  printf("%.15f\n", solve(r));
  return 0;
}
