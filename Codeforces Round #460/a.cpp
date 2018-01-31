#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  double ans = 1e100;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    ans = min(ans, (double) a / b);
  }
  printf("%.15f\n", ans * m);
  return 0;
}
