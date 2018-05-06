
#include <bits/stdc++.h>

using namespace std;

const int N = 15;
const double eps = 1e-6;

int n, s, y;
int v[N], d[N], p[N], c[N];

double l[N], r[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &s, &y);
    for (int i = 0; i < n; i++) scanf("%d", v + i);
    for (int i = 0; i < n; i++) scanf("%d", d + i);
    for (int i = 0; i < n; i++) scanf("%d", p + i);
    for (int i = 0; i < n; i++) scanf("%d", c + i);

    for (int i = 0; i < n; i++) {
      if (d[i] == 1) {
        p[i] = -p[i];
      } else {
        d[i] = -1;
      }
    }

    for (int i = 0; i < n; i++) {
      double dist = p[i] + c[i];
      r[i] = dist / v[i];

      l[i] = (double) p[i] / v[i];
      l[i] -= (double) y / s;

      // printf("%.15f %.15f\n", l[i], r[i]);
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
      if (ans + eps > l[i]) ans = max(ans, r[i]);
      ans += (double) y / s;
    }
    printf("%.15f\n", ans);
  }

  return 0;
}
