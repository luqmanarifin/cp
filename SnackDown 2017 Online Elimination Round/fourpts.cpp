#include <bits/stdc++.h>
 
using namespace std;
 
const long double EPS = 1e-9;
 
struct point {
  long double x, y;
  point(long double x = 0, long double y = 0) : x(x), y(y) {};
  bool operator<(point b) {
    if (fabs(x - b.x) < EPS)
      return y < b.y;
    return x < b.x;
  }
  point operator-(point b) {
    return point(x-b.x, y-b.y);
  }
  point operator+(point b) {
    return point(x+b.x, y+b.y);
  }
  point operator*(long double k) {
    return point(x*k, y*k);
  }
  point operator/(long double k) {
    return point(x/k, y/k);
  }
};
long double dist(point a, point b) {
  return hypot(a.x-b.x, a.y-b.y);
}
long double cross(point a, point b, point c) {
  return (a.x-b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x);
}
// (LINE)
struct line { long double a,b,c; };
void pointToLine(point p1, point p2, line *l) {
  if(p1.x == p2.x) {
    l->a = 1.0; l->b = 0.0; l->c = -p1.x;
  }
  else {
    l->a = -(long double)(p1.y-p2.y)/(p1.x-p2.x);
    l->b = 1.0;
    l->c = -(long double)(l->a * p1.x) - (l->b * p1.y);
  }
}
long double distLine(point p, line l) {
  return fabs(p.x * l.a + p.y * l.b + l.c) / hypot(l.a, l.b);
}
 
bool areParallel(line l1, line l2) {
  return fabs(l1.a-l2.a) < EPS && fabs(l1.b-l2.b) < EPS;
}
bool areIntersect(line l1, line l2, point * p) {
  if(areParallel(l1, l2)) return false;
  
  p->x = (l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b - l1.a*l2.b);
  if(fabs(l1.b) > EPS)
    p->y = -(l1.a*p->x + l1.c);
  else
    p->y = -(l2.a*p->x + l2.c);
  return true;
}
vector< line > boundary;
 
point p[4];
 
bool solve(point a, point b, point c, point d, vector< point > & ans) {
  line l;
  line la, lb;
  pointToLine(a, b, &l);
  pointToLine(a, c, &la);
  pointToLine(b, d, &lb);
  point aa = (a-b)/dist(a, b), bb = (b-a)/dist(a, b);
  long double mid = 0;
  if (areParallel(la, lb))
    mid = dist(a, b)/2;
  point ca = a + (aa * mid), cb = b + (bb * mid);
  if (fabs(ca.x) > 1e6 || fabs(ca.y) > 1e6 || fabs(cb.x) > 1e6 || fabs(cb.y) > 1e6) {
    return 0;
  }
  pointToLine(ca, c, &la);
  pointToLine(cb, d, &lb);
  point e;
  if (areIntersect(la, lb, &e)) {
    if (fabs(dist(ca, c) + dist(e, c) - dist(e, ca)) < EPS && 
      fabs(dist(cb, d) + dist(e, d) - dist(e, cb)) < EPS) {
      ans.clear();
    // cerr << a.x << " " << a.y << endl;
    // cerr << b.x << " " << b .y << endl;
    // cerr << c.x << " " << c.y << endl;
    // cerr << d.x << " " << d.y << endl;
    // cerr << ca.x << " - " << ca.y << endl;
    // cerr << cb.x << " - " << cb .y << endl;
    // cerr << e.x << " - " << e.y << endl;
    // cerr << fabs(dist(ca, c) + dist(e, c) - dist(e, ca)) <<  " | " << fabs(dist(cb, d) + dist(e, d) - dist(e, cb)) << endl;
      ans.push_back(ca);
      ans.push_back(cb);
      ans.push_back(e);
      return 1;
    }
  }
  return 0;
}
 
int main() {
  line l;
  int t;
  cout << fixed << setprecision(20);
  cin >> t;
  while (t--) {
    for (int i = 0; i < 4; i++) {
      long double x, y;
      cin >> x >> y;
      p[i] = point(x, y);
    }
    sort(p, p+4);
    vector< point > ans;
    for (int i = 0; i < 4 && ans.empty(); i++) {
      for (int j = i+1; j < 4 && ans.empty(); j++) {
        for (int k = j+1; k  < 4 && ans.empty(); k++) {
          if (fabs(cross(p[i], p[j], p[k])) < EPS) {
            for (int z = 0; z < 4; z++) if (z != j)
              ans.push_back(p[z]);
          }
        }
      }
    }
    for (int i = 0; i < 4 && ans.empty(); i++) {
      for (int j = 0; j < 4 && ans.empty(); j++) {
        if (i == j) continue;
        vector< point > ot;
        for (int k = 0; k < 4; k++) {
          if (k == i || k == j) continue;
          if (cross(p[i], p[j], p[k]) < -EPS) break;
          ot.push_back(p[k]);
        }
        if (ot.size() == 2) {
          if (solve(p[i], p[j], ot[0], ot[1], ans))
            break;
          else if (solve(p[i], p[j], ot[1], ot[0], ans))
            break;
        }
      }
    }
    if (!ans.empty()) {
      cout << "YES";
      for (int i = 0; i < 3; i++)
        cout << " " << ans[i].x << " " << ans[i].y;
      cout << "\n";
      // for (int i = 0; i < 4; i++) {
      //   bool ok = 0;
      //   for (int j = 0; j < 3; j++)
      //     for (int k = j+1; k < 3; k++) {
      //       ok |= fabs(dist(ans[j], p[i]) + dist(p[i], ans[k]) - dist(ans[j], ans[k])) < 1e-9;
      //     }
      //   assert(ok);
      // }
    }
    else
      cout << "NO\n";
  }
  return 0;
} 