#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const double PI = acos(-1.);

double ask(double x, double r) {
  return (x + r) * PI * r * r - (PI*x*x*x/3 + PI*r*r*r/3);
}

double R[N], x[N], y[N], z[N];
double ans[N];

int main() {
  int n, s;
  scanf("%d %d", &n, &s);
  double vol = (double) 1e15;
  for (int i = 1; i <= n; i++) {
    scanf("%lf %lf %lf %lf", R + i, x + i, y + i, z + i);
    vol -= 4./3*PI*R[i]*R[i]*R[i];
  }
  vol /= s;
  for (int d = 1; d <= s; d++) {
    double l = ans[d-1];
    double r = 1e5;
    for (int it = 0; it < 75; it++) {
      double mid = (l + r) / 2;
      double now = (mid - ans[d-1]) * 1e10;
      for (int i = 1; i <= n; i++) {
        if (z[i] - R[i] > mid) continue;
        if (z[i] + R[i] < ans[d-1]) continue;
        double rr = min(z[i] + R[i], mid);
        double ll = max(z[i] - R[i], ans[d-1]);
        rr -= z[i];
        ll -= z[i];
        now -= ask(rr, R[i]) - ask(ll, R[i]);
      }
      if (now > vol) {
        r = mid;
      } else {
        l = mid;
      }
    }
    ans[d] = l;
  }
  for (int i = 1; i <= s; i++) {
    double niki = (ans[i] - ans[i-1]) / 1000;
    printf("%.15f\n", niki);
  }
  return 0;
}
