#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-13;

int main() {
  double ans = 0.0;
  int n;
  scanf("%d", &n);
  long long t = 1;
  for(int i = 1; i <= n; i++) {
    t *= i;
  }
  double now = 1;
  for(int i = 1; i <= t; i++) {
    now /= (t + 1 - i);
    double cur = (i - 1) * now;
    if(now < eps) {
      break;
    } else {
      ans += cur;
    }
  }
  printf("%.6f\n", ans);
  return 0;
}
