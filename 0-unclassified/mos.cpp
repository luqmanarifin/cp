#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-13;

double x[35], y[35];

double equal(double a, double b) {
  return abs(a - b) < eps;
}

double dist(double dx, double dy) {
  return sqrt(dx * dx + dy * dy);
}

int find(int cx, int cy) {
  int cur = 0;
  for(int k = 0; k < n; k++) {
    if(dist(x[k] - cx, y[k] - cy) - eps < r) {
      cur++;
    }
  }
  return cur;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    double r;
    scanf("%d %lf", &n, &r);
    r /= 2;
    for(int i = 0; i < n; i++) {
      scanf("%lf %lf", x + i, y + i);
    }
    int ans = 1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        double cx, cy;
        if(equal(x[i], x[j]) && equal(y[i], y[j])) {
          cx = x[i], cy = y[i];
        } else {
          double dx = abs(x[i] - x[j]);
          double dy = abs(y[i] - y[j]);
          double xd = dx * r / (dx + dy);
          double yd = dy * r / (dx + dy);
          cx = x[i] + (x[i] < x[j]? xd : -xd);
          cy = y[i] + (y[i] < y[j]? yd : -yd);
        }
        ans = max(ans, find(cx, cy));
        
        double dx = abs(x[i] - x[j]);
        double dy = abs(y[i] - y[j]);
        double xd = dx / 2;
        double yd = dy / 2;
        cx = x[i] + (x[i] < x[j]? xd : -xd);
        cy = y[i] + (y[i] < y[j]? yd : -yd);
        ans = max(ans, find(cx, cy));
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
