#include <bits/stdc++.h>

using namespace std;

#define point pair<double, double>
#define x first
#define y second

bool circle2PtsRad(point p1, point p2, double r, point *c) { // answer at *c
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
  double det = r * r / d2 - 0.25;
  if(det<0.0) return false;
  double h = sqrt(det);
  c->x = (p1.x + p2.x) * 0.5 + (p1.y-p2.y)*h;
  c->y = (p1.y + p2.y) * 0.5 + (p2.x-p1.x)*h;
  return true;
}

int main() {
  point a = point(0, 0);
  point b = point(1, 0);
  point* c;
  bool ret = circle2PtsRad(b, a, 3, c);
  printf("%d %.15f %.15f\n", ret, c->first, c->second);
  
  return 0;
}