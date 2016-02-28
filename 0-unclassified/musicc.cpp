#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-13;

int main() {
  double t, s, q;
  scanf("%lf %lf %lf", &t, &s, &q);
  double now = s;
  int ans = 0;
  while(now < t - eps) {
    now = now / (1 - (q - 1) / q);
    //printf("%.15f\n", now);
    ans++;
  }
  cout << ans << endl;
  return 0;
}
