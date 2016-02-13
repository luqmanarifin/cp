#include <bits/stdc++.h>

using namespace std;

const int offset = 15000;
const double eps = (double) 1e-15;

const int off = 5000;
const int N = 10000;

double dp[offset * 2], temp[offset * 2];
double a[N];
int num[N];

bool equal(double p, double q) {
  return (p < q? q - p : p - q) < eps;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", num + i);
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      a[off + num[i] - num[j]] += (double) 2 / (n * (n - 1));
    }
  }
  dp[offset] = (double) 1;
  for(int it = 0; it < 2; it++) {
    for(int i = 0; i < offset*2; i++) temp[i] = 0;
    for(int i = 0; i <= offset; i++) {
      if(equal(dp[i], 0)) continue;
      for(int j = off - i; j < off; j++) {
        temp[i - off + j] += dp[i] * a[j];
      }
    }
    for(int i = 0; i < offset * 2; i++) {
      dp[i] = temp[i];
    }
  }
  for(int it = 0; it < 1; it++) {
    for(int i = 0; i < offset*2; i++) temp[i] = 0;
    for(int i = 0; i <= offset; i++) {
      if(equal(dp[i], 0)) continue;
      for(int j = off + 1; j <= off + 4999; j++) {
        temp[i - off + j] += dp[i] * a[j];
      }
    }
    for(int i = 0; i < offset * 2; i++) {
      dp[i] = temp[i];
    }
  }
  double ans = 0;
  for(int i = offset + 1; i < 2 * offset; i++) {
    ans += dp[i];
  }
  printf("%.15f\n", (double) ans);
  return 0;
}