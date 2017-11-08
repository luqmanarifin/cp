#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.);

struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  bool operator<(point p) const {
    if (fabs(x - p.x) > EPS)
      return x < p.x;
    return y < p.y;
  }
  bool operator==(point p) const {
    return (fabs(x - p.x) < EPS) && (fabs(y - p.y) < EPS);
  }
  point operator+(point p) const { return point(x+p.x, y+p.y);}
  point operator-(point p) const { return point(x-p.x, y-p.y);}
  point operator*(double s) const { return point(x*s, y*s);}
};

// rotate p by theta degrees CCW w.r.t origin(0, 0)
point rotate(point p, double tetha) {
  // rotate matrix R(theta0 = [cos(theta) -sin(theta)]
  //                          [sin(theta)  cos(theta)]
  double rad = tetha * PI / 180.0;
  return point(p.x*cos(rad) - p.y*sin(rad),
               p.x*sin(rad) + p.y*cos(rad));
}

double dist(point a, point b) {
  return hypot(a.x - b.x, a.y - b.y);
}

double dot(point a, point b) {
  return a.x * b.x + a.y * b.y;
}
double norm_sq(point p) {
  return dot(p, p);
}

struct line { double a,b,c; };
void pointToLine(point p1, point p2, line& l) {
  if(fabs(p1.x - p2.x) < EPS) {
    l.a = 1.0; l.b = 0.0; l.c = -p1.x;
  }
  else {
    l.a = -(double)(p1.y - p2.y)/(p1.x - p2.x);
    l.b = 1.0;
    l.c = -(double)(l.a * p1.x) - (l.b * p1.y);
  }
}

double distToLine(point p, point a, point b, point & c) {
  point ap = p-a, ab = b-a;
  double u = dot(ap, ab) / norm_sq(ab);
  c = a + ab * u;
  return dist(p, c);
}

const int N = 105;

point p[N];

point rotate(point source, point dest) {
  dest = dest - source;
  return rotate(dest, 90) + source;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &p[i].x, &p[i].y);
  }
  double ans = 1e9;
  // point to point
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // cek semua titik di antara
      
      // jawaban = jarak
    }
  }
  
  // line to point
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      // cek semua titik di antara
      
      // jawaban = jarak
    }
  }
  return 0;
}
