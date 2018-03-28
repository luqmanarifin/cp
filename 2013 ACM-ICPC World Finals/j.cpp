#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

const LD EPS = 1e-7;

inline bool eq(LD x, LD y) { return fabs(x-y) < EPS; }
inline bool lt(LD x, LD y) { return x + EPS < y; }
inline bool le(LD x, LD y) { return x < y + EPS; }
inline int sgn(LD x) { return eq(x, 0) ? 0 : x < 0 ? -1 : 1; }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(point p) { return point(x+p.x, y+p.y); } 
  point operator-(point p) { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x * s, y * s); } 
  point operator/(LD s) { return point(x / s, y / s); }
  LD operator*(point p) { return x * p.x + y * p.y; }
  LD operator%(point p) { return x * p.y - p.x * y; }
  LD norm_sq() { return *this * *this; }
  LD norm() { return sqrt(*this * *this); }
  bool operator==(point p) const { return eq(x, p.x) && eq(y, p.y); } 
  bool operator<(point p) const { return eq(x, p.x) ? lt(y, p.y) : lt(x, p.x); } 
};
ostream& operator<<(ostream& o, point p) { return o << "(" << p.x << ", " << p.y << ")"; }

LD dist2(point a, point b) {
  return (b - a).norm_sq();
}

void intersect(point a, point b, LD r, vector<point>& p) {
  point ab = b-a;
  LD rr = r * r;
  LD A = ab * ab, B = 2 * (a * ab), C = a * a - rr;
  LD det = B * B - 4 * A * C;
  // cerr << det << endl;
  if (lt(det, 0)) return;
  det = sqrt(det);
  LD t1 = (-B - det) / (2 * A), t2 = (-B + det) / (2 * A);
  // cerr << t1 << " " << t2 << endl;
  if (le(0, t1) && le(t1, 1)) {
    p.push_back(a + ab * t1);
  }
  if (le(0, t2) && le(t2, 1)) {
    p.push_back(a + ab * t2);
  }
  // cerr << ok << " ok " << a << " " <<  p  << " " << b << endl;
}

int ccw(point a, point b, point c) {
  return sgn((b - a) % (c - b));
}

LD area(vector<point> vp) {
  int n = vp.size();
  if (n <= 2) return 0;
  LD ans = vp.back() % vp[0];
  for (int i = 0; i+1 < n; ++i)
    ans += vp[i] % vp[i+1];
  return fabs(ans) * 0.5;
}

bool onSeg(point a, point b, point c) {
  if (ccw(a, b, c) != 0) return 0;
  return le((a - b) * (c - b), 0); 
}


// check if point p inside (CONVEX/CONCAVE) polygon vp
// 0 on boundary, -1 inside, 1 outside
int pointVsPolygon(point p, vector< point >& vp) {
  int wn = 0, n = (int)vp.size();
  auto next = [n](int id) { return id == n-1 ? 0 : id+1; };
  for(int i = 0; i < n; i++) {
    int cs = ccw(vp[next(i)], vp[i], p);
    if(cs == 0 && le((vp[next(i)]-p) * (vp[i]-p), 0))
      return 0; // between(vp[i], p, vp[i+1])
    if(le(vp[i].y, p.y)) {
      if(lt(p.y, vp[next(i)].y) && cs > 0)
        wn++;
    }
    else {
      if(le(vp[next(i)].y, p.y) && cs < 0)
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

LD tembereng(LD d, LD r) {
  LD tri = d * sqrt(r * r - 0.25 * d * d) * 0.5;
  LD juring = asin(d/(2 * r)) * r * r;
  // cerr << d << " tembereng " << r << " " << juring << " " << tri << endl;
  return juring - tri;
}

int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  vector<point> vp;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vp.push_back(point(x, y));
  }
  auto next = [n](int id) { return id == n-1 ? 0 : id+1; };
  vector<point> inter;
  for (int i = 0; i < n; ++i) {
    intersect(vp[i], vp[next(i)], r, inter);
  }
  sort(inter.begin(), inter.end());
  inter.erase(unique(inter.begin(), inter.end()), inter.end());
  if (inter.size() <= 1) {
    LD ans = 0;
    bool ok = 1;
    for (point p : vp) {
      if (lt(r * r, p.norm_sq()))
        ok = 0;
    }
    if (ok) {
      ans = area(vp);
    }
    printf("%.9lf\n", (double)ans);
    return 0;
  }
  reverse(inter.begin(), inter.end());
  vector<point> now = vp;
  now.push_back(now[0]);
  for (int i = 0; i + 1 < inter.size(); ++i) {
    now = cutPolygon(inter[i], inter[i+1], now);
  }
  if (now.size() > 1 && now[0] == now.back())
    now.pop_back();
  LD ans = area(now);
  // for (point p : now)
  //   cerr << p << endl;
  for (int i = 0; i + 1 < inter.size(); ++i) {
    point b = (inter[i] + inter[i+1]) / 2;
    point c = b * ((b.norm() + r) / 2 / b.norm());
    if (pointVsPolygon(c, vp) <= 0)
      ans += tembereng((inter[i+1] - inter[i]).norm(), r);
  }
  printf("%.9lf\n", (double)ans);
  return 0;
} 