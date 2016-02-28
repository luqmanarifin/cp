#include <bits/stdc++.h>

using namespace std;

int r[105];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", r + i);
  }
  sort(r, r + n);
  reverse(r, r + n);
  double ans = 0;
  for(int i = 0; i < n; i++) {
    if(i % 2 == 0) ans += acos(-1.0) * r[i] * r[i];
    else ans -= acos(-1.0) * r[i] * r[i];
  }
  printf("%.15lf\n", ans);
  return 0;
}
