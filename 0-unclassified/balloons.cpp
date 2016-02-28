#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-12;

int main() {
  long long R, h;
  scanf("%I64d %I64d", &R, &h);
  long long ans = h / R * 2;
  long long H = h / R * R;
  if(2 * H <= 2 * h - R) {
    ans += 2;
    H += R;
  }
  double t = (double) R * sqrt(3) / 2;
  if(H + t - eps < h + R) {
    ans++;
  }
  cout << ans << endl;
  return 0;
}