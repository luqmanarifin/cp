#include <bits/stdc++.h>

using namespace std;

#define point pair<long long, long long>
#define x first
#define y second

long long cross(point p, point q, point r) {
  return (p.x - q.x) * (r.y - q.y) - (p.y - q.y) * (r.x - q.x);
}

int main() {
  long long a, b, c, d, e, f;
  scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &a, &b, &c, &d, &e, &f);
  if ((c - a)*(c - a) + (d - b)*(d - b) == (e - c)*(e - c) + (f - d)*(f - d) && cross(point(a, b), point(c, d), point(e, f))) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}