#include <bits/stdc++.h>

/**
 * biar terluka
 * biar tersiksa
 * aku cuma bisa
 * mencintaimu..
 *
 * Bandung, 7 Februari 2014
 */

using namespace std;

const double eps = 1e-12;

int l[15], r[15];

bool equal(double a, double b) {
  return abs(a - b) < eps;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", l + i, r + i);
  }
  double ans = 0.0;
  for(int i = 1; i <= 10000; i++) {
    for(int win = 0; win < n; win++) {
      if(i <= r[win]) {
        for(int t = 1; t < (1 << n); t++) {
          if(t & (1 << win)) continue;
          double cur = 1.0;
          for(int und = 0; und < n; und++) if(t & (1 << und)) {
            if(l[und] <= i && i <= r[und]) cur *= (double) 1 / (r[und] - l[und] + 1);
            else cur *= 0.0;
          }
          for(int other = 0; other < n; other++) {
            if(other == win || (t & (1 << other))) continue;
            double temp = (double) (min(i, r[other] + 1) - l[other]) / (r[other] - l[other] + 1);
            cur *= max(0.0, temp);
          }
          //printf("%d win, bid %d, prob %.3lf, t %d\n", win + 1, i, cur, t);
          int up = r[win] - max(l[win] - 1, i);
          cur = cur / (r[win] - l[win] + 1) * (up + 1.0 * (l[win] <= i) / (1 + __builtin_popcount(t)));
          ans += cur * i;
        }
      }
    }
  }
  printf("%.18lf\n", ans);
  return 0;
}