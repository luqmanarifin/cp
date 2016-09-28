#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

typedef pair<double, double> point;

double cross(point p, point q, point r) {
  return (p.first - q.first) * (r.second - q.second) - (p.second - q.second) * (r.first - q.first);
}

#define p first
#define q second

bool equal(double a, double b) {
  return abs(a - b) < eps;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    point a, b, c;
    scanf("%lf %lf %lf %lf %lf %lf", &a.first, &a.second, &b.first, &b.second, &c.first, &c.second);
    if (equal(a.first, b.first) && equal(a.second, b.second) && equal(b.first, c.first) && equal(b.second, c.second)) {
      printf("%.6f %.6f\n", a.first, a.second);
    } else if (equal(cross(a, b, c), 0)) {
      vector<pair<point, int> > s;
      s.push_back(make_pair(a, 0));
      s.push_back(make_pair(b, 1));
      s.push_back(make_pair(c, 2));
      sort(s.begin(), s.end());
      pair<point, int> sa = s[0];
      pair<point, int> sb = s[2];
      if (sa.second > sb.second) {
        swap(sa, sb);
      }
      a = sa.first;
      b = sb.first;
      printf("%.6f %.6f %.6f %.6f\n", a.first, a.second, b.first, b.second);
    } else {
      printf("%.6f %.6f %.6f %.6f %.6f %.6f\n", a.first, a.second, b.first, b.second, c.first, c.second);
    }
  }

  return 0;
}
