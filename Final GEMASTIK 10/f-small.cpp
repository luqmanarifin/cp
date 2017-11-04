#include <bits/stdc++.h>

using namespace std;

const long double PI = acos(-1);

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int x, y;
    scanf("%d %d", &x, &y);
    long double dist = hypot(x, y);
    long double area = dist / cos(PI/m);
    printf("%.12lf\n", (double)area);
  } 

  return 0;
}