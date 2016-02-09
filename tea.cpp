#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int n, w;
  scanf("%d %d", &n, &w);
  for(int i = 0; i < 2 * n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + 2 * n);
  double ans = min((double) a[0], (double) a[n] / 2);
  ans = min(ans, (double) w / (3 * n));
  ans *= 3 * n;
  printf("%.15lf\n", ans);
  return 0;
}
