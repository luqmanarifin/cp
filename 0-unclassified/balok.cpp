#include <bits/stdc++.h>

using namespace std;

double pyth(int a, int b) {
  return sqrt(a * a + b * b);
}

int main() {
  int test;
  scanf("%d", &test);
  while(test--) {
    int p, l, t;
    scanf("%d %d %d", &p, &l, &t);
    printf("%.15f %.15f %.15f\n", min(pyth(p, l + t), min(pyth(l, p + t), pyth(t, p + l))), (double) (p + l + t), (double) sqrt(p*p + l*l + t*t));
  }
  return 0;
}
