
#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.);

int A = 0;
int B = 100;

double toRad(double c) {
  return c * PI / 180;
}

double solve(double c) {
  c = toRad(c);
  return A * sin(c) + B * cos(c);
}

int main() {
  double l = 0, r = 90;
  for (int it = 0; it < 100; it++) {
    double lf = (l + l + r) / 3;
    double rf = (l + r + r) / 3;
    if (solve(lf) > solve(rf)) {
      r = rf;
    } else {
      l = lf;
    }
  }
  printf("terbaik di %.15f: %.15f\n", l, solve(l));
  for (int i = 0; i <= 90; i++) {
    printf("%d: %.15f\n", i, solve(i));
  }

  return 0;
}
