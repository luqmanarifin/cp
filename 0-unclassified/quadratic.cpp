#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  double waw = sqrt(b * b - 4 * a * c);
  double l = (-b + waw)/(2*a);
  double r = (-b - waw)/(2*a);
  printf("%.15f\n%.15f\n", max(l, r), min(l, r));
  return 0;
}