#include <bits/stdc++.h>

using namespace std;

const double inf = 1e18;

int main() {
  double ans = inf;
  int a, b;
  scanf("%d %d", &a, &b);
  int n;
  scanf("%d", &n);
  while (n--) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    double d = sqrt((a - u)*(a - u) + (b - v)*(b - v));
    ans = min(ans, d / c);
  }
  printf("%.15f\n", ans);
  return 0;
}
