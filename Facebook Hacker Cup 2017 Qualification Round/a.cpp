#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

double toDegree(double a) {
  return a * 180 / PI;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    double p;
    int x, y;
    scanf("%lf %d %d", &p, &x, &y);
    p = p * 360 / 100;
    //printf("%.15f %d %d\n", p, x, y);
    
    double deg = toDegree(atan2(x - 50, y - 50));
    int d = (x - 50)*(x - 50) + (y - 50)*(y - 50);
    if (deg < 0) deg += 360;
    
    //printf("%.15f %d\n", deg, d);
    printf("Case #%d: ", tt);
    if (deg <= p && d <= 50*50) {
      puts("black");
    } else {
      puts("white");
    }
  }

  return 0;
}
