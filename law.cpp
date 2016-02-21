#include <bits/stdc++.h>

using namespace std;

double t = 1.000000011;

double power(double a, int b) {
  if(b == 0) return 1;
  double tmp = power(a, b / 2);
  tmp *= tmp;
  if(b & 1) {
    tmp = tmp * a;
  }
  return tmp;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  printf("%.15f\n", n * power(t, k));
  return 0;
}