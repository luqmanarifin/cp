#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-13;

double dist(int a, int b, int c, int d) {
  return sqrt((a - c)*(a - c) + (b - d)*(b - d));
}

int main() {
  int a, b, c, d, e, f;
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
  double dis = dist(a, b, d, e);
  double ans;
  //printf("%.15f %.15f\n", dis + min(c, f) - eps, (double) max(c, f));
  if(c + f - eps < dis) {                             // normal
    ans = dis - c - f;
  } else if(dis + min(c, f) - eps < max(c, f)) {      // inner
    ans =  max(c, f) - dis - min(c, f);
  } else {                                            // berpotongan
    ans = 0.0;
  }
  printf("%.15f\n", ans / 2);
  return 0;
}
