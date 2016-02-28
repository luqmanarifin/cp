#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-10;
const double inf = 1e9;

bool equal(double a, double b) {
  return abs(a - b) < eps;
}

double arith(double a, double r) {
  return a / (1 - r);
}

double self(int a, int b, int c) {
  return a * (a - 1) / 2 + b * (b - 1) / 2 + c * (c - 1) / 2;
}

double f[105][105][105];
int r, s, p;

double find(int a, int b, int c) {
  if(r < a || s < b || p < c) {
    return f[a][b][c] = 0.0;
  }
  double& ret = f[a][b][c];
  if(!equal(ret, inf)) {
    return ret;
  }
  double dem = (double) (a + b + c + 1) * (a + b + c) / 2;
  ret = 0;
  if(!equal(self(a + 1, b, c), dem)) {
    ret += arith((a + 1) * c * find(a + 1, b, c) / dem, self(a + 1, b, c) / dem);
  }
  if(!equal(self(a, b + 1, c), dem)) {
    ret += arith((b + 1) * a * find(a, b + 1, c) / dem, self(a, b + 1, c) / dem);
  }
  if(!equal(self(a, b, c + 1), dem)) {
    ret += arith((c + 1) * b * find(a, b, c + 1) / dem, self(a, b, c + 1) / dem);
  }
  //printf("%d %d %d %.4lf\n", a, b, c, ret);
  return ret;
}

int main() {
  for(int i = 0; i < 105; i++) {
    for(int j = 0; j < 105; j++) {
      for(int k = 0; k < 105; k++) {
        f[i][j][k] = inf;
      }
    }
  }
  scanf("%d %d %d", &r, &s, &p);
  f[r][s][p] = 1.0;
  
  double ans = 0;
  for(int i = 1; i <= r; i++) {
    ans += find(i, 0, 0);
  }
  printf("%.15f ", ans);
  
  ans = 0;
  for(int i = 1; i <= s; i++) {
    ans += find(0, i, 0);
  }
  printf("%.15f ", ans);
  
  ans = 0;
  for(int i = 1; i <= p; i++) {
    ans += find(0, 0, i);
  }
  printf("%.15f\n", ans);
  return 0;
}
