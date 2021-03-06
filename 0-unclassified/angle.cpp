#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

#define pi acos(-1.0)

double p[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    p[i] = atan2(b, a);
    p[i] *= 180. / pi;
  }
  sort(p, p + n);
  double ans = -(p[0] - p[n - 1]);
  for(int i = 1; i < n; i++) {
    ans = min(ans, 360. - (p[i] - p[i - 1]));
  }
  printf("%.15lf\n", ans);
  return 0;
}
