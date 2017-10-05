#include <bits/stdc++.h>

using namespace std;

const int N = 50;
const int lim = 10;

int n;
double rx[N], ry[N], h[N], k[N], painted;

void dfs(int level, double p1, double q1, double p2, double q2) {
  if (level == lim) {
    bool ok = 0;
    double p = (p1 + p2) / 2;
    double q = (q1 + q2) / 2;
    for (int i = 0; i < n; i++) {
      if ((p-h[i])*(p-h[i])/(rx[i]*rx[i]) + (q-k[i])*(q-k[i])/(ry[i]*ry[i]) <= 1) {
        ok = 1;
        break;
      }
    }
    if (ok) painted += (p2 - p1)*(q2 - q1);
    return;
  }
  double mx = (p1 + p2) / 2;
  double my = (q1 + q2) / 2;
  dfs(level + 1, p1, q1, mx, my);
  dfs(level + 1, p1, my, mx, q2);
  dfs(level + 1, mx, q1, p2, my);
  dfs(level + 1, mx, my, p2, q2);
}

int p1[N], q1[N], p2[N], q2[N];

double dist(double a, double b, double c, double d) {
  return sqrt((a - c)*(a - c) + (b - d)*(b - d));
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d %d %lf", p1 + i, q1 + i, p2 + i, q2 + i, rx + i);
      rx[i] /= 2;
      h[i] = (p1[i] + p2[i]) / 2;
      k[i] = (q1[i] + q2[i]) / 2;
      double f = dist(h[i], k[i], p1[i], q1[i]);
      ry[i] = sqrt(rx[i]*rx[i] - f * f);
      //printf("hk %.5f %.5f: f %.5f: %.5f\n", h[i], k[i], f, ry[i]);
    }
    painted = 0;
    dfs(0, -50, -50, 50, 50);
    //printf("painted %.15f\n", painted);
    double percent = (1 - painted / (100 * 100)) * 100;
    int ans = (int) (percent + 0.5);
    printf("%d%\n", ans);
  }
  return 0;
}
