#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-13;
const double EPS = 1e-6;
const long long INF = 2e9;

class Point {
public:
  Point() : x(0), y(0) {}
  Point(int _x, int _y) : x(_x), y(_y) {}
  Point(long long _x, long long _y) : x(_x), y(_y) {}
  bool operator< (Point other) const {
    if(x != other.x) return x < other.x;
    return y < other.y;
  }
  bool operator== (Point other) const {
    return x == other.x && y == other.y;
  }
  long long x, y;
};

long long cross(Point a, Point o, Point b) {
  long long dxao = o.x - a.x;
  long long dyao = o.y - a.y;
  long long dxob = b.x - o.x;
  long long dyob = b.y - o.y;
  return dxao * dyob - dxob * dyao;
}

bool collinear(Point a, Point o, Point b) {
  return cross(a, o, b) == 0;
}

bool ccw(Point a, Point o, Point b) {
  return cross(a, o, b) >= 0;
}

Point pivot;

long long dist(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool angle_cmp(Point a, Point b) {
  if(collinear(pivot, a, b)) {
    return dist(a, pivot) < dist(b, pivot);
  }
  long long xa = a.x - pivot.x;
  long long xb = b.x - pivot.x;
  long long ya = a.y - pivot.y;
  long long yb = b.y - pivot.y;
  return atan2(ya, xa) < atan2(yb, xb);
}

bool cmp(Point a, Point b) {
  return a.y < b.y || (a.y == b.y && a.x < b.x);
}

vector<Point> CH;

void ConvexHull(vector<Point> P) {
  int n = (int) P.size();
  if(n < 3) {
    P.push_back(P[0]);
    CH = P;
    return;
  }
  int PO = 0;
  for(int i = 1; i < n; i++) {
    if(P[i].y < P[PO].y || (P[i].y == P[PO].y && P[i].x > P[PO].x)) {
      PO = i;
    }
  }
  swap(P[0], P[PO]);
  pivot = P[0];
  sort(++P.begin(), P.end(), angle_cmp);
  int k = P.size() - 1;
  while(k && collinear(P[0], P[k-1], P[k])) k--;
  reverse(P.begin() + k, P.end());
  //FORS(i, P.size()) pf("%lld %lld\n", P[i].x, P[i].y);
  //puts("-");
  vector<Point> S;
  S.push_back(P[n-1]);
  S.push_back(P[0]);
  S.push_back(P[1]);
  int i = 2;
  while(i < n) {
    int j = (int) S.size() - 1;
    if(ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
    else S.pop_back();
  }
  CH = S;
}

double angle(Point b, Point a, Point c) {
  long long A = (b.x-c.x)*(b.x-c.x) + (b.y-c.y)*(b.y-c.y);
  long long B = (a.x-c.x)*(a.x-c.x) + (a.y-c.y)*(a.y-c.y);
  long long C = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
  return acos((B + C - A) / (2 * sqrt(B) * sqrt(C)));
}

bool between(Point a, Point p, Point b) {
  return cross(a, p, b) == 0
  && min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)
  && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}


bool onSegment(Point p, Point q, Point r)
{
  return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}
 
int orientation(Point p, Point q, Point r)
{
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0) return 0; 
  return (val > 0)? 1: 2; 
}
 
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);
  if (o1 != o2 && o3 != o4) return true;
  if (o1 == 0 && onSegment(p1, p2, q1)) return true;
  if (o2 == 0 && onSegment(p1, q2, q1)) return true;
  if (o3 == 0 && onSegment(p2, p1, q2)) return true;
  if (o4 == 0 && onSegment(p2, q1, q2)) return true;
  return false;
}
 
// Returns true if the point p lies inside the polygon[] with n vertices
bool isInside(vector<Point> polygon, int n, Point p)
{
  assert(n > 3);
  Point pola = Point(INF, p.y);
  Point polb = Point(-INF, p.y);
  int cnta = 0, cntb = 0;
  for(int i = 1; i < n; i++) {
    if(between(polygon[i - 1], p, polygon[i])) {
      return 1;
    }
    if(doIntersect(polygon[i - 1], polygon[i], p, pola)) {
      cnta++;
    }
    if(doIntersect(polygon[i - 1], polygon[i], p, polb)) {
      cntb++;
    }
  }
  return cnta % 2 && cntb % 2;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<Point> p;
    for(int i = 0; i < n; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      p.push_back(Point(a, b));
    }
    sort(p.begin(), p.end());
    p.resize(distance(p.begin(), unique(p.begin(), p.end())));
    ConvexHull(p);
    /*
    puts("CONVEC");
    for(auto it : CH) {
      printf("%I64d %I64d\n", it.x, it.y);
    }
    */
    if(CH.size() == 2) {
      while(m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        puts(a == CH[0].x && b == CH[0].y? "YA" : "TIDAK");
      }
    } else if(CH.size() == 3) {
      while(m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        puts(between(CH[0], Point(a, b), CH[1])? "YA" : "TIDAK");
      }
    } else {
      while(m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        puts(isInside(CH, CH.size(), Point(a, b))? "YA" : "TIDAK");
      }
    }
  }
  
  return 0;
}
