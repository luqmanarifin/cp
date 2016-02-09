#include <bits/stdc++.h>

using namespace std;

double r, x, y, xi, yi;

int main() {
  scanf("%lf %lf %lf %lf %lf", &r, &x, &y, &xi, &yi);
  double dist = sqrt((x - xi)*(x - xi) + (y - yi)*(y - yi));
  printf("%d\n", (int) ceil(dist / (2*r)));
  
  return 0;
}