#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int x[N];
double y[N];

int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  for (int i = 0; i < n; i++) {
    scanf("%d", x + i);
    y[i] = r;
    for (int j = 0; j < i; j++) {
      if (abs(x[j] - x[i]) <= 2 * r) {
        int dx = abs(x[j] - x[i]);
        double dy = sqrt(4*r*r - dx*dx);
        y[i] = max(y[i], y[j] + dy);
      }
    }
  }
  for (int i = 0; i < n; i++) printf("%.15f ", y[i]);
  return 0;
}
