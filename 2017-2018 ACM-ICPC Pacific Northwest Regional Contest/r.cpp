#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const double eps = 1e-7;

int n, X;
double v;

int li[N], ri[N];
double vi[N];

int normal;

double find_vy(double vx) {
  return sqrt(v * v - vx * vx);
}

double solve(double vx, double vy) {
  double ret = (double) normal / vx * vy;
  for (int i = 0; i < n; i++) {
    int len = ri[i] - li[i];
    ret += (double) len / vx * (vy + vi[i]);
  }
  return ret;
}

int main() {
  scanf("%d %d %lf", &n, &X, &v);
  normal = X;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %lf", li + i, ri + i, vi + i);
    normal -= ri[i] - li[i];
  }
  double vx_min = v / 4;
  double vy = find_vy(vx_min);
  double l = -vy, r = vy;
  for (int it = 0; it < 300; it++) {
    double mid = (l + r) / 2;
    if (solve(find_vy(mid), mid) > 0) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (abs(solve(find_vy(r), r)) > eps) {
    puts("Too hard");
    return 0;
  }
  double vx_ans = find_vy(r);
  if (vx_ans < v / 2 - eps) {
    puts("Too hard");
    return 0;
  }
  printf("%.3f\n", X / vx_ans);
  return 0;
}
