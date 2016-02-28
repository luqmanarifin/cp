#include <bits/stdc++.h>

using namespace std;

const double inf = 1e13;
const double eps = 1e-13;

double ri[105], ci[105];

int main() {
  int tc;
  scanf("%d", &tc);
  for(int tt = 1; tt <= tc; tt++) {
    int n;
    double v, x;
    double mini = inf, maxi = -1;
    scanf("%d %lf %lf", &n, &v, &x);
    for(int i = 0; i < n; i++) {
      scanf("%lf %lf", &ri[i], &ci[i]);
      mini = min(mini, ci[i]);
      maxi = max(maxi, ci[i]);
    }
    printf("Case #%d: ", tt);
    if(x < mini || maxi < x) {
      puts("IMPOSSIBLE");
      continue;
    }
    double l = 0.0, r = inf + 10.0;
    for(int it = 0; it < 300; it++) {
      double t = (l + r) / 2;
      double kalor = 0, sum = 0;
      for(int i = 0; i < n; i++) {
        sum += t * ri[i];
        kalor += t * ri[i] * ci[i];
      }
      if(sum < v || kalor < v * x) {
        l = t;
      } else {
        r = t;
      }
    }
    printf("%.15lf\n", l);
  }
  
  return 0;
}
