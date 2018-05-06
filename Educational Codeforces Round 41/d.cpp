
#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
const LD EPS = 1e-9, PI = acos(-1);
inline bool eq(LD a, LD b) { return fabs(a-b) < EPS; }
inline bool lt(LD a, LD b) { return a + EPS < b; }
inline bool le(LD a, LD b) { return a < b + EPS; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point  {
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
  line() {}
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

struct item {
  item() : id(0) {}
  item(int a) : id(0) {}
  item(line l) : id(1), l(l) {}
  item(point p) : id(2), p(p) {}
  int id;   // 0 gak, 1 line, 2 point
  line l;
  point p;
};

const int N = 1e5 + 5;

pair<int, int> a[N];
vector<pair<pair<int, int>, pair<int, int>>> all;

item join(item l, item r) {
  if (l.id > r.id) swap(l, r);
  if (l.id == 0) return item(0);
  if (r.id == 1) {
    if (l.l.areSame(r.l)) {
      return item(l.l);
    } else {
      return item(0);
    }
  }
  if (l.id == 1) {
    if (l.l.onLine(r.p)) {
      return item(l.l);
    } else {
      return item(0);
    }
  }
  if (l.id == 2) {
    return item(line(l.p, r.p));
  }
  assert(0);
}

struct segtree {
  segtree(int n) : n(n) {
    num.resize(n << 2);
    build(1, 0, n - 1);
  }
  void build(int p, int l, int r) {
    if (l == r) {
      num[p] = item(point(a[l].first, a[l].second));
      // printf("asu %d %d\n", l, num[p].id);
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    num[p] = join(num[p + p], num[p + p + 1]);
  }
  item find(int l, int r) {
    return get(1, 0, n - 1, l, r);
  }
  item get(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return num[p];
    int mid = (l + r) >> 1;
    item ret;
    if (ll <= mid && mid < rr) {
      ret = join(get(p + p, l, mid, ll, mid), get(p + p + 1, mid + 1, r, mid + 1, rr));
    } else if (ll <= mid) {
      ret = get(p + p, l, mid, ll, rr);
    } else {
      ret = get(p + p + 1, mid + 1, r, ll, rr);
    }
    return ret;
  }
  vector<item> num;
  int n;
} ;

segtree* seg;
int n;

void check(int l, int r) {
  if (l <= r) {
    item ret = seg->find(l, r);
    if (ret.id == 0) return;
  }
  if (1 <= l - 1 && r + 1 <= n - 1) {
    item ret = join(seg->find(1, l - 1), seg->find(r + 1, n - 1));
    if (ret.id > 0) {
      puts("YES");
      exit(0);
    }
  } else if (1 <= l - 1) {
    if (seg->find(1, l - 1).id) {
      puts("YES");
      exit(0);
    }
  } else if (r + 1 <= n - 1) {
    if (seg->find(r + 1, n - 1).id) {
      puts("YES");
      exit(0);
    }
  } else {
    puts("YES");
    exit(0);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a[i].first, &a[i].second);
  }
  int pl = a[0].first;
  int pr = a[0].second;
  for (int i = 0; i < n; i++) {
    auto ori = a[i];
    a[i].first -= pl;
    a[i].second -= pr;
    if (a[i].first == 0) {
      a[i].second = 1;
    } else if (a[i].second == 0) {
      a[i].first = 1;
    } else {
      int g = __gcd(abs(a[i].first), abs(a[i].second));
      a[i].first /= g;
      a[i].second /= g;
    }
    if (a[i].first < 0) {
      a[i].first = -a[i].first;
      a[i].second = -a[i].second;
    }
    // printf("ori %d %d: %d %d\n", ori.first, ori.second, a[i].first, a[i].second);
    all.emplace_back(a[i], ori);
  }
  sort(all.begin(), all.end());
  for (int i = 0; i < n; i++) a[i] = all[i].second;
  seg = new segtree(n);
  // for (int i = 0; i < n; i++) printf("point %d %d\n", a[i].first, a[i].second);
  
  check(1, n - 1);
  for (int i = 1; i < n; i++) {
    int j = i;
    while (j + 1 < n && all[j + 1].first == all[j].first) j++;
    check(i, j);
    // printf("wow %d %d\n", i, j);
    i = j;
  }
  // for (int i = 0; i < n; i++) {
  //   for (int j = i; j < n; j++) {
  //     printf("%d %d: %d\n", i, j, seg->find(i, j).id);
  //   }
  // }
  puts("NO");
  return 0;
}
