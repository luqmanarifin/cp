#include <bits/stdc++.h>

using namespace std;

int main() {
  int l, p, q;
  scanf("%d %d %d", &l, &p, &q);
  printf("%.15f\n", 1. * p / (p + q) * l);
  return 0;
}
