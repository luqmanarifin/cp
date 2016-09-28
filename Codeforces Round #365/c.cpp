#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

typedef pair<long long, long long> Point;
#define q first
#define r second

Point p[N];

long long cross(Point a, Point b, Point c) {
  return (a.q - b.q) * (c.r - b.r) - (c.q - b.q) * (a.r - b.r);
}

int main() {
  int n, w, v, u;
  scanf("%d %d %d %d", &n, &w, &v, &u);
  for (int i = 0; i < n; i++) scanf("%I64d %I64d", &p[i].q, &p[i].r);
  bool up = 1, down = 1;
  Point now = Point(0, 0);
  for (int i = 0; i < n; i++) {
    long long ret = cross(Point(v, u), now, p[i]);
    up &= (ret >= 0);
    down &= (ret <= 0);
  }
  if (up || down) {
    printf("%.15f\n", (double) w / u);
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (cross(Point(now.q + v, now.r + u), now, p[i]) < 0) {
      now = p[i];
    }
  }
  double ans = (double) now.q/v + (double) (w - now.r)/u;
  printf("%.15f\n", ans);
  return 0;
}
