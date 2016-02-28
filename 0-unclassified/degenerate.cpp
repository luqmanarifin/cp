#include <bits/stdc++.h>

using namespace std;

int main() {
  double a, b, c, d;
  scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
  double l = -1e15, r = 1e15;
  for(int it = 0; it < 1000; it++) {
    double mid = (l + r) / 2;
    double aa = a + mid;
    double dd = d + mid;
    double bb = b - mid;
    double cc = c - mid;
    if(aa / cc < bb / dd) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%.15lf\n", l);
  return 0;
}
