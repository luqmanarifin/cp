#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

bool equal(double a, double b) {
  return abs(a - b) < eps;
}

int main() {
  double y1, y2, yw, xb, yb, rad;
  scanf("%lf %lf %lf %lf %lf %lf", &y1, &y2, &yw, &xb, &yb, &rad);
  yw -= rad;
  if(equal(xb, rad)) {
    puts("-1");
    return 0;
  }
  int tt = 50;
  double l = 0.0, r = xb;
  while(tt--) {
    double mid = (l + r) / 2;
    double m = (yb - yw)/(mid - xb);
    double c = yw - m * mid;
    double p = m;
    double q = -1;
    double rr = c;
    double d = abs(p*0 + q*y2 + rr) / sqrt(p*p + q*q);
    double mantul = -rr / q;
    //printf("jarak %.18lf %.18lf %.18lf\n", d, mid, mantul);
    if(y2 < mantul || d <= rad + eps) l = mid;
    else if(mantul <= y1 + rad + eps) r = mid;
    else {
      printf("%.18lf\n", mid);
      return 0;
    }
  }
  puts("-1");
  return 0;
}