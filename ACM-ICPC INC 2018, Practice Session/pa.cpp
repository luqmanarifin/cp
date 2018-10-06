#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  double mn = 1e100, mx = -1e100, sum = 0;
  for (int i = 0; i < n; i++) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    double c = (double) a / b;
    mn = min(mn, c);
    mx = max(mx, c);
    sum += c;
  }
  printf("%.15f %.15f %.15f\n", mn, mx, sum);
  return 0;
}
