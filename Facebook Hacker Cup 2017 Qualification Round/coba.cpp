#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

double toDegree(double a) {
  return a * 180 / PI;
}

int main() {
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      printf("%d %d %.15f\n", i, j, toDegree(atan2(i, j)));
    }
  }
  return 0;
}
