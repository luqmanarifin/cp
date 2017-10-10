#include <bits/stdc++.h>

using namespace std;

const int N = 50;
const int lim = 10;

int n;
double rx[N], ry[N], h[N], k[N];
int p1[N], q1[N], p2[N], q2[N];
int painted, all;

double dist(double a, double b, double c, double d) {
  return sqrt((a - c)*(a - c) + (b - d)*(b - d));
}

void dfs(int level, double a, double b, double c, double d) {
  if (level == lim) {
    bool ok = 0;
    double p = (a + c) / 2;
    double q = (b + d) / 2;
    for (int i = 0; i < n; i++) {
      if (dist(p, q, p1[i], q1[i]) + dist(p, q, p2[i], q2[i]) <= rx[i]) {
        ok = 1;
        break;
      }
    }
    if (ok) painted++;
    all++;
    return;
  }
  double mx = (a + c) / 2;
  double my = (b + d) / 2;
  dfs(level + 1, a, b, mx, my);
  dfs(level + 1, a, my, mx, d);
  dfs(level + 1, mx, b, c, my);
  dfs(level + 1, mx, my, c, d);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d %d %lf", p1 + i, q1 + i, p2 + i, q2 + i, rx + i);
      h[i] = (p1[i] + p2[i]) / 2;
      k[i] = (q1[i] + q2[i]) / 2;
      double f = dist(h[i], k[i], p1[i], q1[i]);
    }
    painted = all = 0;
    dfs(0, -50, -50, 50, 50);
    //printf("painted %.15f\n", painted);
    double percent = (1 - (double) painted / all) * 100;
    int ans = (int) (percent + 0.5);
    printf("%d%\n", ans);
  }
  return 0;
}
