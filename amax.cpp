#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    double x, y, z;
    scanf("%lf %lf %lf", &x, &y, &z);
    printf("%.2lf\n", (x + y + z)*(x + y + z)/2 - (x*x + y*y + z*z));
  }
  
  return 0;
}
