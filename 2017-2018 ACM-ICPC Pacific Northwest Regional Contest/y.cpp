#include <bits/stdc++.h>

using namespace std;

const int N = 1e8 + 5;

int main() {
  int k, p, x;
  scanf("%d %d %d", &k, &p, &x);
  double ans = 1e100;
  for (int i = 1; i < N; i++) {
    double cur = (double) i * x + (double) k / i * p;
    ans = min(ans, cur);
  }
  printf("%.3f\n", ans);
  return 0;
}
