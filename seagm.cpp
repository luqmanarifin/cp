#include <bits/stdc++.h>

using namespace std;
 
const double eps = 1e-10;
const int N = 1e4 + 5;
const double lim = 1e11;
const int shift = 10000;
const long long en = 10000000000000000LL;

bool equal(double a, double b) {
  return abs(a - b) < eps;
}

int a[15][N];
double b[15][N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        scanf("%lf", &b[i][j]);
        a[i][j] = (int) (b[i][j] * 10000 + 0.5);
      }
      sort(a[i], a[i] + m);
      sort(b[i], b[i] + m);
    }
    if(a[0][0] == 0) {
      assert(equal(b[0][0], 0.0));
      printf("%.6lf\n", 0);
      continue;
    }
    if(n <= 4 && m <= 4) {
      long long c[5];
      long long sum = 0;
      for(int i = 0; i < n; i++) {
        c[i] = 1;
        for(int j = 0; j < m; j++) {
          c[i] *= a[i][j];
        }
        sum += c[i];
      }
      int ret[7];
      //assert(c[0] <= sum);
      //assert(c[0] > 0 && sum > 0);
      for(int i = 0; i < 7; i++) {
        ret[i] = c[0] / sum;
        c[0] = c[0] % sum * 10;
      }
      if(c[0] / sum >= 5) {
        ret[6]++;
        for(int i = 6; i > 0 && ret[i] == 10; i--) {
          ret[i] = 0;
          ret[i - 1]++;
        }
      }
      printf("%d.", ret[0]);
      for(int i = 1; i <= 6; i++) {
        printf("%d", ret[i]);
      }
      printf("\n");
      continue;
    }
    double dem = 1.0;
    for(int i = 1; i < n; i++) {
      double cur = 1.0;
      for(int j = 0; j < m; j++) {
        cur = cur * a[i][j] / a[0][j];
      }
      dem += cur;
      if(dem > lim) break;
    }
    printf("%.6lf\n", (double) (1.0 / dem));
  }
  
  return 0;
}