#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.);

// (POINT)
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

double dist(point a, point b) {
  return hypot(a.x - b.x, a.y - b.y);
}

double cross(point a, point b) {
  return a.x * b.y - a.y * b.x;
}

double dot(point a, point b) {
  return a.x * b.x + a.y * b.y;
}
double norm_sq(point p) {
  return dot(p, p);
}

// return 1 = ccw, 0 = colinear, -1 = cw
int ccw(point p, point q, point r) {
  point pq = q - p, pr = r-p;
  double crs = cross(pq, pr);
  if (fabs(crs) < EPS) return 0;
  return crs > 0 ? 1 : -1;
}

// Graham’s Scan Algorithm
// need implement operator<,-,cross,ccw on Point’s library
double dist2(point a, point b) {// norm_sq(b - a)
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
point pivot;
bool angle_cmp(point a, point b) {
  if(ccw(pivot, a, b) == 0)
    return dist2(a, pivot) < dist2(b, pivot);
  return ccw(pivot, a, b) > 0;
}

// hasil convexHull tidak siklik(P[0] != P.back())
void convexHull(vector<point> & P) {
  int i, j, n = (int) P.size();
  if(n < 3) {
    return;
  }
  int PO = 0;
  for(i = 1; i < n; i++) {
    if(P[i] < P[PO]) {
      PO = i;
    }
  }
  swap(P[0], P[PO]);
  pivot = P[0];
  sort(++P.begin(), P.end(), angle_cmp);
  // if point on boundary is included then uncomment this:
  // int k = (int)P.size()-1; while (k-1 > 0 && ccw(P[0], P[k-1], P.back()) == 0) k--;
  // reverse(P.begin() + k, P.end());
  vector<point> S;
  S.push_back(P[0]);
  S.push_back(P[1]);
  i = 2;
  while(i < n) {
    j = (int) S.size() - 1;
    // if point on boundary is included then ccw >= 0
    if(j < 1 || ccw(S[j-1], S[j], P[i]) > 0) S.push_back(P[i++]);
    else S.pop_back();
  }
  P = S;
}

double distToLine(point p, point a, point b, point & c) {
  point ap = p-a, ab = b-a;
  double u = dot(ap, ab) / norm_sq(ab);
  c = a + ab * u;
  return dist(p, c);
}

const int N = 105;

int main() {
  int n;
  scanf("%d", &n);
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &p[i].x, &p[i].y);
  }
  convexHull(p);
  double ans = 1e18;
  for (int i = 0; i < p.size(); i++) {
    for (int j = 0; j < p.size(); j++) {
      if (i == j || i == (j + 1) % p.size()) continue;
      point a = p[j];
      point b = p[(j + 1) % p.size()];
      point tmp;
      double lim = distToLine(p[i], a, b, tmp);
      bool ok = 1;
      for (int k = 0; k < p.size(); k++) {
        double cur = distToLine(p[k], a, b, tmp);
        if (cur > lim) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        ans = min(ans, lim);
      }
    }
  }
  printf("%.15f\n", ans);
  return 0;
}
