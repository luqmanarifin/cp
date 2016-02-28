#include <bits/stdc++.h>

using namespace std;

const double inf = 1e13;
const double eps = 1e-13;

bool equal(double a, double b) {
  return abs(a - b) < eps;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n;
    double v, x;
    printf("Case #%d: ", tt);
    scanf("%d %lf %lf", &n, &v, &x);
    if(n == 1) {
      double r, c;
      scanf("%lf %lf", &r, &c);
      if(equal(c, x)) {
        printf("%.15lf\n", v / r);
      } else {
        puts("IMPOSSIBLE");
      }
    } else {
      double r1, c1, r2, c2;
      scanf("%lf %lf %lf %lf", &r1, &c1, &r2, &c2);
      if(c1 > c2) {
        swap(c1, c2);
        swap(r1, r2);
      }
      if(x < c1 - eps || c2 < x - eps) {
        puts("IMPOSSIBLE");
        continue;
      }
      double t1 = x - c1;
      double t2 = c2 - x;
      double tot = t1 + t2;
      if(equal(tot, 0.0)) {
        printf("%.15lf\n", v / (r1 + r2));
        continue;
      }
      double l1 = t2 * v / tot;
      double l2 = t1 * v / tot;
      printf("%.15lf\n", max(l1 / r1, l2 / r2));
    }
  }
  
  return 0;
}
