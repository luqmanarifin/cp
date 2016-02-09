#include <bits/stdc++.h>

using namespace std;

const double PI = 3.1415926535897932384626433832795;

int main() {
  double a, r;
  scanf("%lf %lf", &a, &r);
  double teta = asin(a / (2 * r));
  double t = sqrt(r*r - a*a/4);
  double L = teta / 2 * (r * r);
  L -= a * t / 4;
  printf("%.15f\n", 2 * L);
  return 0;
}
