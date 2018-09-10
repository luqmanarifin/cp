#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  double ans = 0;
  if (m < k) {
    ans = (double) m / k;
  } else {
    int blue = m - (k - 1);
    int all = n + blue;
    ans = (double) (k - 1) / k + (double) blue / all / k;
  }
  printf("%.15f\n", ans);
  return 0;
}
