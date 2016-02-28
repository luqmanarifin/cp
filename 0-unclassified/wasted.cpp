#include <bits/stdc++.h>

using namespace std;

double dist(int a, int b, int c, int d) {
  return sqrt((a - c)*(a - c) + (b - d)*(b - d));
}

int main() {
  double all = 0;
  int n, k, x, y;
  scanf("%d %d", &n, &k);
  scanf("%d %d", &x, &y);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    all += dist(x, y, a, b);
    x = a; y = b;
  }
  all *= k;
  printf("%.15lf\n", all / 50.0);
  
  return 0;
}