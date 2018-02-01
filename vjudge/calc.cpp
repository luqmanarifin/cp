#include <bits/stdc++.h>

using namespace std;

const int N = 3005;

double a[N], c[N];
int n;
double goal;

double solve() {
  for (int i = 1; i <= n; i++) {
    a[i + 1] = 2 * (a[i] + c[i]) - a[i-1];
  }
  return a[n + 1];
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    scanf("%lf %lf", &a[0], &goal);
    for (int i = 1; i <= n; i++) scanf("%lf", &c[i]);
    double l = -1e9, r = 1e9;
    for (int it = 0; it < 150; it++) {
      double mid = (l + r) / 2;
      a[1] = mid;
      if (solve() < goal) {
        l = mid;
      } else {
        r = mid;
      }
    }
    printf("%.2f\n", l);
    if (t) puts("");
  }
  return 0;
}
