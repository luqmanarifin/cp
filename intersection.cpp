#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1.)

int c[6];

int main() {
  long double x1, y1, r1, x2, y2, r2;
  for(int i = 0; i < 6; i++) scanf("%d", c + i);
  x1 = c[0];
  y1 = c[1];
  r1 = c[2];
  x2 = c[3];
  y2 = c[4];
  r2 = c[5];
  long double d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
  if(d >= r1 + r2) {
    puts("0");
    return 0;
  }
  if(d <= abs(r1 - r2)) {
    printf("%.22f\n", (double)(PI * min(r1, r2) * min(r1, r2)));
    return 0;
  }
  long double a1 = acos((r2*r2 + d*d - r1*r1)/(2*r2*d));
  long double s1 = a1*r2*r2;
  long double t1 = r2*r2*sin(a1)*cos(a1);
  long double a2 = acos((r1*r1 + d*d - r2*r2)/(2*r1*d));
  long double s2 = a2*r1*r1;
  long double t2 = r1*r1*sin(a2)*cos(a2);
  printf("%.22f\n", (double)(s1+s2-t1-t2));
  return 0;
}
