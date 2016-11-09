#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int a[N];
double dist[N];
double dp[N];
double b, r, v, e, f;

int main() {
  int n;
  scanf("%d", &n);
  while (n) {
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    scanf("%lf %lf %lf %lf %lf", &b, &r, &v, &e, &f);
    for (int i = 1; i < N; i++) {
      dist[i] = dist[i - 1];
      int x = i - 1;
      if (x < r) {
        dist[i] += 1.0 / (v - f * (r - x));
      } else {
        dist[i] += 1.0 / (v - e * (x - r));
      }
    }
    fill(dp, dp + N, 1e18);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        double cur = dist[a[i] - a[j]] + (i != n? b : 0);
        dp[i] = min(dp[i], dp[j] + cur);
      }
    }
    printf("%.15f\n", dp[n]);
    
    scanf("%d", &n);
  }

  return 0;
}
