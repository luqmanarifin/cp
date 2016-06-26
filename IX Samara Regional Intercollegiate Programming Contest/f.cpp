#include <bits/stdc++.h>

using namespace std;

double dist(double a, double b, double c, double d) {
  return (c - a)*(c - a) + (d - b)*(d - b);
}

int a, b, c, d, e, f, g, h;

double after(double tl) {
  return dist(a + e*tl, b + f*tl, c + g*tl, d + h*tl);
}

int main() {
  scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);
  double l = 0, r = 2e4;
  for(int i = 0; i < 300; i++) {
    double tl = l + (r - l) / 3;
    double tr = r - (r - l) / 3;
    //printf("%.10f %.10f %.10f %.10f\n", tl, tr, after(tl), after(tr));
    if(after(tl) < after(tr)) {
      r = tr;
    } else {
      l = tl;
    }
  }
  printf("%.15f\n", sqrt(after(l)));
  return 0;
}
