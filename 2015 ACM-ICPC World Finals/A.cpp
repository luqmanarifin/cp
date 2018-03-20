#include <bits/stdc++.h>

using namespace std;

double a, b, c, d;
int p;
int n;
double maks = -1e9;
double ans = 0;

double calculate(int x){
  return p * (sin(a * x + b) + cos(c * x + d) + 2);
}

int main() {
  scanf("%d%lf%lf%lf%lf%d", &p, &a, &b, &c, &d, &n);
  maks = calculate(1);
  for(int i = 2; i <= n; ++i){
    double price = calculate(i);
    ans = max(ans, maks - price);
    maks = max(maks, price);
    // fprintf(stderr, "%d %lf %lf\n", i, price, maks);
  }
  printf("%.10lf\n", ans);
  return 0;
}
