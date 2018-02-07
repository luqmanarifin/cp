#include <bits/stdc++.h>

using namespace std;

typedef double ld;
const ld eps = 1e-7;
inline bool equal(ld a, ld b) { return fabs(b-a) < eps; }
inline bool eqless(ld a, ld b) { return a < b + eps; }
inline bool less(ld a, ld b) { return a + eps < b; }
inline int sign(ld x) { return equal(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  ld x, y;
  point(ld x = 0, ld y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x+p.x, y+p.y); }
  point operator-(point p) { return point(x-p.x, y-p.y); }
  point operator*(ld s) { return point(x*s, y*s); }
  point operator/(ld s) { return point(x/s, y/s); }
  ld operator%(point p) { return x * p.y - y * p.x; }
  ld operator*(point p) { return x * p.x + y * p.y; }
  ld norm_sq() { return *this * *this; }
  ld norm() { return sqrt(*this * *this); }
  point rotate(ld cs, ld sn) { return point(x*cs-y*sn, x*sn+y*cs); }
  point rotate(ld angle) { return rotate(cos(angle), sin(angle)); }
  bool operator==(point p) { return equal(x, p.x) && equal(y, p.y); }
  bool operator<(point p) { return equal(x, p.x) ? x < p.x : y < p.y; }
};

int ccw(point a, point b, point c) {
  return sign((b-a) % (c-b));
}
ld dist(point a, point b) { return (b-a).norm(); }
ld dist2(point a, point b) { return (b-a).norm_sq(); }
ld angle(point a, point o, point b) {
  point oa = a-o, ob = b-o;
  return acos(oa*ob/(oa.norm()*ob.norm()));
}

struct line {
  point a, ab; // p(t) = a + ab * t
  line(point ta = point(), point tb = point()) {
    if (tb < ta) swap(ta, tb);
    a = ta; ab = tb-ta;
  }
  point b() { return a + ab; }
  bool isLine() { return !(ab == point()); } // minor
  operator bool() { return !(ab == point()); } // minor
  // Line
  bool onLine(point p) {
    if (ab == point()) return a == p;
    return equal(ab % (p-a), 0);
  }
  ld distLine(point p) {
    if (ab == point()) return dist(a, p);
    return fabs((p-a) % ab)/ab.norm();
  }
  point projection(point p) {
    if (ab == point()) return a;
    return a + ab * ((p-a) * ab / ab.norm_sq());
  }
  point reflection(point p) {
    return projection(p) * 2.0 - p;
  }
  bool areParallel(line l) {
    return equal(ab % l.ab, 0);
  }
  bool areSame(line l) {
    return areParallel(l) && onLine(l.a) && l.onLine(a);
  }
};

line perp(point a, point b) {
  point c = (a + b) / 2.0;
  point cx = (b-a).rotate(0, 1);
  line l;
  l.a = c;
  l.ab = cx;
  return l;
}

bool areIntersect(line l1, line l2, point & res) {
  if (l1.areParallel(l2)) return 0;
  ld ls = (l2.a  - l1.a) % l2.ab, rs = l1.ab % l2.ab;
  res = l1.a + l1.ab * ls/rs;
  return 1;
}

const int N = 44;
ld d[N];
vector<line> vl;
vector<point> vp;
int n;
int calc(point c) {
  for (int k = 0; k < n; ++k) {
    d[k] = dist2(vp[k], c);
  }
  sort(d, d+n);
  ld last = d[0];
  int now = 1;
  for (int k = 0; k < n; ++k) {
    if (!equal(last, d[k])) {
      ++now;
      last = d[k];
    }
  }
  return now;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp.push_back(point(x, y));
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (vp[i] == vp[j]) continue;
      vl.push_back(perp(vp[i], vp[j]));
    }
  }
  int ans = n;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      point c = (vp[i]+vp[j]) / 2.0;
      ans = min(ans, calc(c));
    }
  }
  for (int i = 0; i < vl.size(); ++i) {
    for (int j = i+1; j < vl.size(); ++j) {
      point c;
      if (areIntersect(vl[i], vl[j], c)) {
        ans = min(ans, calc(c));
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}