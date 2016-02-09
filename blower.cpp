#include <bits/stdc++.h>

using namespace std;

const double inf = 1e18;
const int N = 1e5 + 5;

#define PI acos(-1.)

long long a[N], b[N], pa, pb;

double dist(double c, double d) {
  return (pa - c)*(pa - c) + (pb - d)*(pb - d);
}

int main() {
  int n;
  scanf("%d %I64d %I64d", &n, &pa, &pb);
  for(int i = 0; i < n; i++) {
    scanf("%I64d %I64d", &a[i], &b[i]);
  }
  double mn = inf, mk = -inf;
  for(int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    double da = a[j] - a[i], db = b[j] - b[i];
    double l = 0, r = 1;
    for(int it = 0; it < 100; it++) {
      double lf = l + (r - l) / 3;
      double rf = r - (r - l) / 3;
      if(dist(a[i] + lf*da, b[i] + lf*db) < dist(a[i] + rf*da, b[i] + rf*db)) {
        r = rf;
      } else {
        l = lf;
      }
    }
    mn = min(mn, dist(a[i] + l*da, b[i] + l*db));
    mk = max(mk, dist(a[i], b[i]));
  }
  printf("%.15f\n", (double) PI * (mk - mn));
  return 0;
}
