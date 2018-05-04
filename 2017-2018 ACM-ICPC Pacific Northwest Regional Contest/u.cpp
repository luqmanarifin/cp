#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;

double a[10];

int main() {
  for (int i = 1; i <= 6; i++) scanf("%lf", a + i);
  double ans = 1e100;
  for (int i = 1; i <= 6; i++) {
    if (a[i] < eps) continue;
    double now = 0;
    for (int j = 1; j <= 6; j++) {
      if (i == j) continue;
      now += j * a[j];
    }
    double cur = (3.5 - now) / a[i];
    ans = min(ans, fabs(cur - i));
  }
  printf("%.3f\n", ans);
  return 0;
}
