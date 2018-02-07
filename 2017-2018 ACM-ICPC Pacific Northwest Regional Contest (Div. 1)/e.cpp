#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  double X, v;
  scanf("%d %lf %lf", &n, &X, &v);
  double sum = 0;
  for (int i = 0; i < n; ++i) {
    double l, r, vy;
    scanf("%lf %lf %lf", &l, &r, &vy);
    double len = r-l;
    sum += len * vy;
  }
  double vy = sum/X;
  if (fabs(vy) + 1e-9 > v) {
    puts("Too hard");
    return 0;
  }
  double vx = sqrt(v * v - vy * vy);
  if (v > 2 * vx) {
    puts("Too hard");
    return 0;
  }
  printf("%.3lf\n", X/vx);
  return 0;
}