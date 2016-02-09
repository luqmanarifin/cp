#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const double eps = 1e-13;

double x[N], y[N];
double f[N];

bool equal(double a, double b) {
  return abs(a - b) < eps;
}

double dist(double dx, double dy) {
  return sqrt(dx * dx + dy * dy);
}

int main() {
  double sx, sy, fx, fy;
  scanf("%lf %lf %lf %lf", &sx, &sy, &fx, &fy);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%lf %lf", x + i, y + i);
  }
  x[n] = fx, y[n] = fy;
  priority_queue<pair<double, int>> pq;
  for(int i = 0; i <= n; i++) {
    f[i] = dist(sx - x[i], sy - y[i]) / 5;
    pq.emplace(-f[i], i);
  }
  while(!pq.empty()) {
    double cur; int now;
    tie(cur, now) = pq.top();
    cur = -cur;
    pq.pop();
    if(!equal(cur, f[now])) continue;
    for(int i = 0; i <= n; i++) {
      if(i == now) continue;
      double del = dist(x[now] - x[i], y[now] - y[i]);
      double ncos = min(del / 5, abs(del - 50) / 5 + 2);
      if(cur + ncos < f[i] - eps) {
        f[i] = cur + ncos;
        pq.emplace(-f[i], i);
      }
    }
  }
  printf("%.15f\n", f[n]);
  return 0;
}
