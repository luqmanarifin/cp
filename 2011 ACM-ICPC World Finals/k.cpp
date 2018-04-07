#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
const LD EPS = 1e-9, PI = acos(-1);
inline bool eq(LD a, LD b) { return fabs(a-b) < EPS; }
inline bool lt(LD a, LD b) { return a + EPS < b; }
inline bool le(LD a, LD b) { return a < b + EPS; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x*s, y*s); }
  point operator/(LD s) { return point(x/s, y/s); }
  LD operator*(const point& p) const { return x*p.x + y*p.y; } // dot
  LD operator%(const point& p) const { return x*p.y - y*p.x; } // cross
  LD norm_sq() { return *this * *this; }
  LD norm() { return sqrt(*this * *this); }
  point rotate(LD cs, LD sn) { return point(x*cs-y*sn, x*sn+y*cs); }
  point rotate(LD angle) { return rotate(cos(angle), sin(angle)); }
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};
int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }
LD dist(point a, point b) { return (b-a).norm(); }
LD dist2(point a, point b) { return (b-a).norm_sq(); }
LD angle(point a, point o, point b) {
  point oa = a-o, ob = b-o;
  return acos(oa*ob/(oa.norm()*ob.norm()));
}
point bisector(point a, point b) { return a * b.norm() + b * a.norm(); }

struct line {
  point a, ab; // p(t) = a + ab * t
  line(point ta, point tb) {
    if (tb < ta) swap(ta, tb);
    a = ta; ab = tb-ta;
  }
  point b() { return a + ab; }
  bool isLine() { return !(ab == point()); } // minor
  operator bool() { return !(ab == point()); } // minor
  // Line
  bool onLine(point p) {
    if (ab == point()) return a == p;
    return eq(ab % (p-a), 0);
  }
  LD distLine(point p) {
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
  // Segment
  bool onSegment(point p) {
    if (ab == point()) return a == p;
    point pa = a-p, pb = b()-p;
    return eq(pa % pb, 0) && le(pa * pb, 0);
  }
  LD distSegment(point p) {
    if (le((p-a) * ab, 0)) return dist(a, p);
    if (le(0, (p-b()) * ab)) return dist(b(), p);
    return distLine(p);
  }
  point closestSegment(point p) {
    if (le((p-a) * ab, 0)) return a;
    if (le(0, (p-b()) * ab)) return b();
    return projection(p);
  }
  bool areParallel(line l) {
    return eq(ab % l.ab, 0);
  }
  bool areSame(line l) {
    return areParallel(l) && onLine(l.a) && l.onLine(a);
  }
};
bool areIntersect(line l1, line l2, point & res) {
  if (l1.areParallel(l2)) return 0;
  LD ls = (l2.a  - l1.a) % l2.ab, rs = l1.ab % l2.ab;
  res = l1.a + l1.ab * ls/rs;
  return 1;
}

// (Polygon)
double area(const vector< point > & P) {
  double result = 0.0;
  for(int i = 0; i+1 < (int)P.size(); ++i) {
    result += P[i] % P[i+1]; // cross(P[i], P[i+1]);
  }
  return fabs(result)/2.0;
}

// check if point p inside (CONVEX/CONCAVE) polygon vp
// 0 on boundary, -1 inside, 1 outside
int pointVsPolygon(point p, const vector< point >& vp) {
  int wn = 0, n = (int)vp.size() - 1;
  for(int i = 0; i < n; i++) {
    int cs = ccw(vp[i+1], vp[i], p);
    if(cs == 0 && (vp[i+1]-p) * (vp[i]-p) <= 0)
      return 0; // between(vp[i], p, vp[i+1])
    if(vp[i].y <= p.y) {
      if(vp[i+1].y > p.y && cs > 0)
        wn++;
    }
    else {
      if(vp[i+1].y <= p.y && cs < 0)
        wn--;
    }
  }
  return wn == 0 ? 1 : -1;
}

// line segment p-q intersect with line A-B
point lineIntersectSeg(point p, point q, point A, point B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return point((p.x*v + q.x*u)/(u+v), (p.y*v + q.y*u)/(u+v));
}
// cuts polygon Q along the line formed by point a-> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, vector<point> Q) {
  vector<point> P;
  for(int i = 0; i<(int)Q.size(); i++) {
    double left1 = (b - a) % (Q[i] - a), left2 = 0.0;
    if(i != (int)Q.size()-1) left2 = (b - a) % (Q[i+1] - a);
    if(left1 > -EPS) P.push_back(Q[i]);
    if(left1 * left2 < -EPS)
        P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
    }

    if(P.empty()) return P;
    if(!(P.front() == P.back()))
        P.push_back(P.front());
    return P;
}

const int N = 105;

bool can(line l, vector<point>& p) {
  LD d = dist(l.a, l.b());
  for (int k = 0; k < p.size(); k++) {
    point pro = l.projection(p[k]);
    LD cur = dist(l.a, pro) + dist(l.b(), pro);
    if (lt(d, cur)) return 0;
  }
  return 1;
}

int main() {
  int n;
  scanf("%d", &n);
  int tc = 0;
  while (n) {
    ++tc;
    vector<point> p;
    while (n--) {
      int u, v;
      scanf("%d %d", &u, &v);
      p.push_back(point(u, v));
    }
    LD ans = 1e18;
    for (int i = 0; i < p.size(); i++) {
      for (int j = i + 1; j < p.size(); j++) {
        if (can(line(p[i], p[j]), p)) {
          ans = min(ans, dist(p[i], p[j]));
        }
      }
    }
    for (int i = 0; i < p.size(); i++) {
      for (int k = i + 1; k < p.size(); k++) {
        point l = p[i];
        point r = p[k];
        line LINE = line(l, r);
        set<int> s;
        int at = -1;
        LD farthest = 0;
        for (int j = 0; j < p.size(); j++) {
          LD cur = LINE.distLine(p[j]);
          if (cur > farthest) {
            farthest = cur;
            at = j;
          }
          s.insert(ccw(l, r, p[j]));
        }
        if (s.count(1) && s.count(-1)) continue;
        ans = min(ans, farthest);
      }
    }
    ans *= 100;
    ans = ceil(ans - EPS);
    printf("Case %d: %.2f\n", tc, (double) ans / 100);
    
    scanf("%d", &n);
  }
  
  return 0;
}
