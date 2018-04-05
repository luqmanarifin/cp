#include <bits/stdc++.h>

using namespace std;

const string NAME = "dome";

const int N = 1e4 + 4;
const double eps = 1e-7;

pair<double, double> p[N];
int n;
double solve(double h) {
  double r = -1;
  for (int i = 0; i < n; ++i) {
    double cur = p[i].first * h / (h - p[i].second);
    if (p[i].second + eps > h)
      return -1;
    r = max(r, cur);
  }
  return r;
}


int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif
  scanf("%d", &n);
  double le = 0, ri = 1e9;
  for (int i = 0; i < n; ++i) {
    double x, y, z;
    scanf("%lf %lf %lf", &x, &y, &z);
    p[i] = {sqrt(x * x + y * y), z};
    le = max(le, z + eps);
  }
  for (int it = 0; it < 100; ++it) {
    double il = (le + le + ri) / 3, ir = (le + ri + ri) / 3;
    double rl = solve(il), rr = solve(ir);
    if (rl < eps)
      le = il;
    else if (rr < eps)
      ri = ir;
    else if (rl * rl * il < rr * rr * ir)
      ri = ir;
    else
      le = il;
  }
  double ans = (le + ri) * 0.5;
  printf("%.3lf %.3lf\n", ans, solve(ans));
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
