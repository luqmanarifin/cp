#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], n, p;

bool can(double time) {
  double need_time = 0;
  for (int i = 0; i < n; i++) {
    double need_power = a[i] * time;
    need_power -= b[i];
    if (need_power > 0) {
      need_time += need_power / p;
    }
  }
  return need_time <= time;
}

int main() {
  scanf("%d %d", &n, &p);
  long long tot = 0;
  for (int i = 0; i < n; i++) scanf("%d %d", a + i, b + i);
  for (int i = 0; i < n; i++) {
    tot += a[i];
  }
  if (tot <= p) {
    puts("-1");
    return 0;
  }
  double l = 0, r = 1e14;
  for (int it = 0; it < 150; it++) {
    double mid = (l + r) / 2;
    if (can(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%.15f\n", l);
  return 0;
}