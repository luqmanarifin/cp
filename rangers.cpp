#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-13;

double dist(double a, double b, double c, double d) {
  return sqrt((a - c)*(a - c) + (b - d)*(b - d));
}

int x1, y1, x2, y2;
int v, t;
int vx, vy, wx, wy;
double add;

bool can(double time) {
  double x = x1 + time * vx;
  double y = y1 + time * vy;
  return (dist(x, y, x2, y2) <= (time + add) * v);
}

int main() {
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  int t;
  scanf("%d %d", &v, &t);
  scanf("%d %d %d %d", &vx, &vy, &wx, &wy);
  
  double l = 0, r = t;
  for(int it = 0; it < 300; it++) {
    double mid = (l + r) / 2;
    if(can(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if(abs(t - l) > eps) {
    printf("%.15f\n", l);
    return 0;
  }
  
  add = t;
  x1 += t * vx;
  y1 += t * vy;
  vx = wx;
  vy = wy;
  l = 0, r = 1e9;
  for(int it = 0; it < 300; it++) {
    double mid = (l + r) / 2;
    if(can(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.15f\n", t + l);
  return 0;
}
