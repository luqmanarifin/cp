#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

int main() {
  double a, b, c, d;
  scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
  double r = sqrt((a - c)*(a - c) + (b - d)*(b - d));
  r = r / 4;
  double ans = PI * r * r * 14 / 3;
  printf("%.15f\n", ans);
  return 0;
}
