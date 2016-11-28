#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

double toRad(double a) {
  return a * PI / 180;
}

int main() {
  double R = 117331;
  double S = 875072;
  double n = 82;
  double tri = (S*S*n / (2. * (2.-2.*cos(toRad(360.0 / n)))));
  double cok = PI*R*R / tri;
  double ans = 0.0205;
  double x = ans / cok;
  printf("%.15f\n", x);
  {
  double R = 389028;
  double S = 475634 ;
  double n = 50 ;
  double cok = PI*R*R / (S*S*n / (2. * (2.-2.*cos(toRad(360.0 / n)))));
  double ans = 0.1952;
  double x = ans / cok;
  printf("%.15f\n", x);
  }
  return 0;
}
