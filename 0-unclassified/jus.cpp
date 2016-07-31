#include <bits/stdc++.h>

using namespace std;

#define REMOVE_REDUNDANT

inline int cmp(long long a, long long b) {
    return (a < b) ? -1 : ((a > b) ? 1 : 0);
}

struct Point { // <--> Vector
    long long x, y;
    Point(long long x = 0, long long y = 0) : x(x), y(y) {}

    Point operator + (const Point& a) const { return Point(x+a.x, y+a.y); }
    Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }
    Point operator * (long long k) const { return Point(x*k, y*k); }
    Point operator / (long long k) const { return Point(x/k, y/k); }

    long long operator * (const Point& a) const { return x*a.x + y*a.y; } // dot product
    long long operator % (const Point& a) const { return x*a.y - y*a.x; } // cross product

    int cmp(Point q) const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }

    #define Comp(x) bool operator x (Point q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
    #undef Comp

    Point conj() { return Point(x, -y); }
    long long norm() { return x*x + y*y; }

    // Note: There are 2 ways for implementing len():
    // 1. sqrt(norm()) --> fast, but inaccurate (produce some values that are of order X^2)
    // 2. hypot(x, y) --> slow, but much more accurate
    long long len() { return sqrt(norm()); }
};

int ccw(Point a, Point b, Point c) {
    return cmp((b-a)%(c-a),0);
}
typedef vector< Point > Polygon;

// Convex Hull:
// If minimum point --> #define REMOVE_REDUNDANT
// If maximum point --> no need to change.
// Known issues:
// - Max. point does not work when some points are the same.
// Tested:
// - https://open.kattis.com/problems/convexhull
/*
bool operator<(const Point &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
bool operator==(const Point &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
 */
long long area2(Point a, Point b, Point c) { return a%b + b%c + c%a; }
#ifdef REMOVE_REDUNDANT
bool between(const Point &a, const Point &b, const Point &c) {
    return (area2(a,b,c) == 0 && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

void ConvexHull(vector<Point> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<Point> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

#ifdef REMOVE_REDUNDANT
    if (pts.size() <= 2) return;
    dn.clear();
    dn.push_back(pts[0]);
    dn.push_back(pts[1]);
    for (int i = 2; i < pts.size(); i++) {
        if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
        dn.push_back(pts[i]);
    }
    if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
        dn[0] = dn.back();
        dn.pop_back();
    }
    pts = dn;
#endif
}


// Check point in convex polygon, O(logN)
// Source: http://codeforces.com/contest/166/submission/1392387
// On edge --> false
#define Det(a,b,c) ((long long)(b.x-a.x)*(long long)(c.y-a.y)-(long long)(b.y-a.y)*(c.x-a.x))
bool in_convex(vector<Point>& l, Point p){
    int a = 1, b = l.size()-1, c;
    if (Det(l[0], l[a], l[b]) > 0) swap(a,b);
    // Allow on edge --> if (Det... > 0 || Det ... < 0)
    if (Det(l[0], l[a], p) > 0 || Det(l[0], l[b], p) < 0) return false;
    while(abs(a-b) > 1) {
        c = (a+b)/2;
        if (Det(l[0], l[c], p) > 0) b = c; else a = c;
    }
    // Alow on edge --> return Det... <= 0
    return Det(l[a], l[b], p) <= 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        Polygon jus, awal;
        jus.clear();
        awal.clear();
        scanf("%d%d", &n, &m);
        for(int i = 0; i<n; i++) {
            long long x, y;
            scanf("%lld%lld", &x, &y);
            jus.push_back(Point(x, y));
            awal.push_back(Point(x, y));
        }
        ConvexHull(jus);
        for(int i = 0; i<n; i++) {
            assert(in_convex(jus, awal[i]));
        }
        if (jus.size() == 1) {
          for(int i = 0; i<m; i++) {
              long long x, y;
              scanf("%lld%lld", &x, &y);
              puts(jus[0] == Point(x, y) ? "YA" : "TIDAK");
          }
        } else if (jus.size() == 2) {
          long long mink = min(jus[0].x, jus[1].x);
          long long makk = max(jus[0].x, jus[1].x);
          long long miny = min(jus[0].y, jus[1].y);
          long long maky = max(jus[0].y, jus[1].y);
          for(int i = 0; i<m; i++) {
              long long x, y;
              scanf("%lld%lld", &x, &y);
              puts(Det(jus[0], jus[1], Point(x, y)) && mink <= x && x <= makk && miny <= y && y <= maky? "YA" : "TIDAK");
          }
        } else {
          reverse(jus.begin(), jus.end());
          for(int i = 0; i<m; i++) {
              long long x, y;
              scanf("%lld%lld", &x, &y);
              puts(in_convex(jus, Point(x, y)) ? "YA" : "TIDAK");
          }
        }
    }
    return 0;
}