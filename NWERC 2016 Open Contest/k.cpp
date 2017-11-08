#include <bits/stdc++.h>

using namespace std;
typedef double ld;
const ld EPS = 1e-9;
const ld PI = acos(-1);

// (POINT)
struct point {
  ld x, y;
  point(ld x = 0, ld y = 0) : x(x), y(y) {}
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
  point operator*(ld s) const { return point(x*s, y*s);}
  point operator/(ld s) const { return point(x/s, y/s); }
  ld operator*(point p) const { return x * p.x + y * p.y; }
  ld operator%(point p) const { return x * p.y - y * p.x; }
};

ld dist(point a, point b) {
  return hypot(a.x - b.x, a.y - b.y);
}

// return 1 = ccw, 0 = colinear, -1 = cw
int ccw(point p, point q, point r) {
  point pq = q - p, pr = r-p;
  ld crs = pq % pr;
  if (fabs(crs) < EPS) return 0;
  return crs > 0 ? 1 : -1;
}

bool between(point p, point q, point r) {
  return ccw(p, q, r) == 0 && (p.x-q.x) * (r.x-q.x) < EPS && (p.y-q.y) * (r.y-q.y) < EPS;
}

ld norm(point P) {
  return sqrt(P * P);
}

ld cos_angle(point a, point b, point c) {
  point ba = a - b, bc = c - b;
  return ba * bc / (norm(ba) * norm(bc));
}

point inCenter(point &A, point &B, point &C) {
  ld a = norm(B-C), b = norm(C-A), c = norm(A-B);
  return (A * a + B * b + C * c) / (a + b + c);
}

double distToLineSegment(point p, point a, point b, point &c) {
  point ap = p-a, ab = b-a;
  if (a == b) {
    c = a;
    return dist(p, c);
  }
  ld u = ap * ab / (ab * ab);
  if (u < 0.0) c = a;
  else if (u > 1.0) c = b;
  else c = a + ab * u;
  return dist(p, c);
}

int main() {
  int n;
  scanf("%d", &n);
  vector<point> vp;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp.push_back(point(x, y));
  }
  vp.push_back(vp[0]);
  vp.push_back(vp[1]);
  point a, b;
  bool found = false;
  vector<point> candidate;
  for (int i = 0; i < n; i++) {
    if (ccw(vp[i], vp[i+1], vp[i+2]) >= 0) continue;
    ld cs = cos_angle(vp[i], vp[i+1], vp[i+2]);
    ld sin_half = sqrt(0.5 * (1.0 - cs));
    ld d = 4000.0 / sin_half;
    point c = inCenter(vp[i], vp[i+1], vp[i+2]);
    c = vp[i+1] + (c-vp[i+1]) * (d / dist(vp[i+1], c));
    bool ok = 1;
    for (int j = 0; j < n && ok; j++) {
      point tmp;
      ld rr = distToLineSegment(c, vp[j], vp[j+1], tmp);
      if (rr < 4000.0 - EPS)
        ok = 0;
    }
    if (ok)
      candidate.push_back(c);
  }
  for (int i = 0; i < candidate.size() && !found; i++) {
    for (int j = i+1; j < candidate.size() && !found; j++) {
      if (dist(candidate[i], candidate[j]) < 7999.0 - EPS) continue;
      found = 1;
      a = candidate[i];
      b = candidate[j];
    }
  }
  if (found) {
    printf("%.11lf %.11lf\n", (double)a.x, (double)a.y);
    printf("%.11lf %.11lf\n", (double)b.x, (double)b.y);
  }
  else
    puts("impossible");
  return 0;
}
