#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int lim = 20000;

int t[N], n;
double a[N];

double find(double d) {
  for(int i = 0; i < n; i++) {
    a[i] = t[i] - d;
  }
  double mini = 0.0, maxi = 0.0, curmin = 0.0, curmax = 0.0;
  for(int i = 0; i < n; i++) {
    curmin = min(curmin + a[i], a[i]);
    curmax = max(curmax + a[i], a[i]);
    mini = min(mini, curmin);
    maxi = max(maxi, curmax);
  }
  return max(maxi, -mini);
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", t + i);
  }
  double l = -lim, r = lim;
  for(int it = 0; it < 300; it++) {
    double lef = (2 * l + r) / 3;
    double rig = (l + 2 * r) / 3;
    if(find(lef) > find(rig)) {
      l = lef;
    } else {
      r = rig;
    }
  }
  printf("%.18f\n", find((l + r)/2));
  return 0;
}
