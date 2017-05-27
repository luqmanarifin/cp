#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const double eps = 1e-9;

long long t[N], b[N], n;
double ans;

int main() {
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) scanf("%lld %lld", t + i, b + i);
  double now = 1;
  double tot = 0;
  for (int i = 0; i < n; i++) {
    if (b[i]) {
      ans += (tot + t[i]) * now / 2;
      now /= 2;
    } else {
      tot += (double) t[i] / 2;
    }
  }
  ans += now * tot;
  printf("%.15f\n", ans);
  return 0;
}
