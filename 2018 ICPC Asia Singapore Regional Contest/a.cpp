#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
  ll x, y;
  point (ll x = 0, ll y = 0) : x(x), y(y) {
  }
  point operator+(point p) { return point(x+p.x, y+p.y); }
  point operator-(point p) { return point(x-p.x, y-p.y); }
  ll operator%(point p) { return x * p.y  - y * p.x; }
  ll operator*(point p) { return x * p.x  + y * p.y; }
  bool operator<(point p) const { return make_pair(y, x) < make_pair(p.y, p.x); }
  bool operator==(point p) const { return make_pair(x, y) == make_pair(p.x, p.y); }
};

ll dist(point a, point b) {
  return (b - a) * (b -a);
}

ostream& operator<<(ostream& os, point p) {
  return os << "(" << p.x << "," << p.y << ")";
}

inline int sign(ll x) { return x == 0 ? 0 : x < 0 ? -1 : 1; }

int ccw(point a, point b, point c) {
  return sign((b - a) % (c - b));
}

long long gcd(ll a, ll b) {
  return a ? gcd(b % a, a) : b;
}

const int N = 5050;

int pos[N], sorted[N];

struct event {
  point c;
  int a, b;
  bool operator<(event v) {
    return (c % v.c) > 0;
  }
};

ll area(point a, point b, point c) {
  return abs((a % b) + (b % c) + (c % a));
}

point pivot;

bool cmp_angle(point a, point b) {
  ll crs = ccw(pivot, a, b);
  if (crs == 0)
    return dist(pivot, a) < dist(pivot, b);
  return crs > 0;
}

void convex_hull(vector<point> & vp) {
  int i, j, n = vp.size();
  if (n < 3)
    return;
  int po = 0;
  for (i = 1; i < n; ++i)
    if (vp[i] < vp[po])
      po = i;
  swap(vp[0], vp[po]);
  pivot = vp[0];
  sort(++vp.begin(), vp.end(), cmp_angle);
  vector<point> res;
  res.push_back(vp[0]);
  res.push_back(vp[1]);
  i = 2;
  while (i < n) {
    j = (int)res.size() - 1;
    if (j < 1 || ccw(res[j-1], res[j], vp[i]) > 0) res.push_back(vp[i++]);
    else
      res.pop_back();
  }
  vp = res;
}

int main() {
  int n;
  scanf("%d", &n);
  set<point> sp;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    sp.insert(point(x, y));
  }
  vector<point> vp;
  for (point p : sp) {
    vp.push_back(p);
    // cerr << p << " ? " << endl;
  }
  convex_hull(vp);
  sort(vp.begin(), vp.end());
  n = vp.size();
  for (int i = 0; i < n; ++i) {
    sorted[i] = pos[i] = i;
    // cerr << vp[i] << endl;
  }
  vector<event> ev;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      ev.push_back((event){vp[j] - vp[i], i, j});
    }
  }
  sort(ev.begin(), ev.end());
  for (auto it : ev) {
    ans = max(ans, area(vp[it.a], vp[it.b], vp[sorted[0]]));
    ans = max(ans, area(vp[it.a], vp[it.b], vp[sorted[n-1]]));
    swap(sorted[pos[it.a]], sorted[pos[it.b]]);
    swap(pos[it.a], pos[it.b]);
  }
  printf("%.9lf\n", (double)ans/2);
  return 0;
}