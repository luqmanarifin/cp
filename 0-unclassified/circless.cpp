#include <bits/stdc++.h>

using namespace std;

double a;

double solve(double r) {
  double t = asin(a / (2 * r));
  return t * r * r - a * r * cos(t) / 2;
}

int main() {
  double r, R;
  scanf("%lf %lf %lf", &a, &r, &R);
  printf("%.15f\n", solve(r) + solve(R));
  return 0;
}
