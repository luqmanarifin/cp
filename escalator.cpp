#include <bits/stdc++.h>

using namespace std;

double f[2005], p;

int main() {
  int n, t;
  scanf("%d %lf %d", &n, &p, &t);
  f[0] = 1.0;
  for(int tt = 0; tt < t; tt++) {
    for(int i = n - 1; i >= 0; i--) {
      f[i + 1] += p * f[i];
      f[i] *= (1 - p);
    }
  }
  double ans = 0.0;
  for(int i = 0; i <= n; i++) {
    ans += i * f[i];
  }
  printf("%.15lf\n", ans);
  return 0;
}