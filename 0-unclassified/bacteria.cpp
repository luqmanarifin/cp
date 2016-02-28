#include <bits/stdc++.h>

using namespace std;

int asu[20000000];

const double eps = 1e-9;

int main() {
  long long k, b, n, t;
  scanf("%I64d %I64d %I64d %I64d", &k, &b, &n, &t);
  if(t == 1) {
    cout << n << endl;
    return 0;
  }
  if(k == 1) {
    long long z = 1 + n * b;
    long long now = t;
    long long i = 0;
    while(now < z) {
      i++;
      now += b;
    }
    cout << i << endl;
    return 0;
  }
  long long id = k*t - t + b;
  double a = (double) (k - 1 + b) / id;
  double cur = n + log(a) / log(k);
  if((int) cur + eps < cur) {
    cur += 1.0;
  }
  printf("%d\n", max(0, (int) cur));
  return 0;
}