#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld EPS = 1e-11;
const ld EPS2 = 1e-8;

struct point {
  ld x, y;
  point (ld x = 0, ld y = 0) : x(x) , y(y) {}
  point operator-(point p) const { return point(x - p.x, y - p.y); }
  point operator+(point p) const { return point(x + p.x, y + p.y); }
  ld operator*(point p) const { return x * p.x + y * p.y; }
  ld operator%(point p) const { return x * p.y - y * p.x; }
  point operator*(ld s) const { return point(x * s, y * s); }
  point operator/(ld s) const { return point(x / s, y / s); }
  bool operator==(point p) const { return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS; }
};

ld dist(point a, point b) {
  point ab = b - a;
  return sqrt(ab * ab);
}

double distToLineSegment(point p, point a, point b, point &c) {
  point ap = p-a, ab = b-a;
  if (a == b) {
    c = a;
    return dist(p, c);
  }
  double u = (ap * ab) / (ab * ab);
  if (u < 0.0) c = a;
  else if (u > 1.0) c = b;
  else c = a + ab * u;
  return dist(p, c);
}


double area(const vector< point > & P) {
  double result = 0.0;
  for(int i = 0; i< (int)P.size()-1; i++) {
    result += P[i] % P[i+1]; // cross(P[i], P[i+1]);
  }
  return fabs(result)/2.0;
}

const int N = 1000;

ld varea[N];
ld longest2[N];
int ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  point a, b, c, d;
  vector<ld> va;
  for (int i = 0; i < n; i++) {
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;
    int r;
    cin >> r;
    longest2[i] = (a - b) * (a - b);
    ld longest = dist(a, b), near = dist(c, d);
    ld sum = 0;
    for (int j = 0; j < r; j++) {
      vector<point> cur;
      for (int k = 0; k < 4; k++) {
        point p, q;
        cin >> p.x >> p.y;
        ld d = distToLineSegment(p, a, b, q);
        p = (p - q) * (longest/ near) + q;
        cur.push_back(p);
      }
      cur.push_back(cur[0]);
      sum += area(cur);
    }
    varea[i] = sum;
  }
  ld mlongest = longest2[0];
  for (int i = 1; i < n; i++)
    mlongest = max(mlongest, longest2[i]);
  for (int i = 0; i < n; i++) {
    varea[i] *= mlongest/longest2[i];
    va.push_back(varea[i]);
  }
  sort(va.begin(), va.end());
  ld ma = va.back();
  va.erase(unique(va.begin(), va.end(), [&](ld x, ld y) { return fabs(x - y) / ma < EPS2; }), va.end());
  for (int i = 0; i < n; i++) {
    ld error = fabs(varea[i] - va[0]);
    ans[i] = 0;
    for (int j = 1; j < va.size(); j++) {
      ld terror = fabs(varea[i] - va[j]);
      if (terror < error)
        error = terror, ans[i] = j;
    }
//    cerr << varea[i] << endl;
  }
  for (int i = 0; i < n; i++) {
    printf("%d%c", ans[i] + 1, " \n"[i == n-1]);
  }
  return 0;
}
