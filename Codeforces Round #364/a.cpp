#include <bits/stdc++.h>

using namespace std;

int n, l, v1, v2, k;
int c;
double tmak;

double f(double t) {
  double ans = 0;
  for (int i = 0; i < c; i++) {
    double s = i * t * v1;
    if (s >= l) {
      ans = max(ans, tmak);
      continue;
    }
    double rem = l - s;
    if (t * v2 >= rem) {
      ans = max(ans, i * t + rem / v2);
    } else {
      rem -= t * v2;
      ans = max(ans, i * t + t + rem / v1);
    }
  }
  return ans;
}

int main() {
  scanf("%d %d %d %d %d", &n, &l, &v1, &v2, &k);
  c = (n / k + (n % k? 1 : 0));
  tmak = (double) l / v1;
  double l = 0, r = (double) tmak / c;
  for (int it = 0; it < 200; it++) {
    double lf = l + (r - l) / 3;
    double rf = r - (r - l) / 3;
    if (f(lf) < f(rf)) {
      r = rf;
    } else {
      l = lf;
    }
  }
  printf("%.15f\n", f(l));
  printf("%.15f\n", l);
  printf("%.15f\n", f(2));
  return 0;
}
