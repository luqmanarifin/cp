#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

double a[N], dp[N];

int main() {
  int n;
  scanf("%d", &n);
  while(n) {
    for(int i = 1; i < n; i++) {
      scanf("%lf", a + i);
    }
    dp[n - 1] = 1;
    for(int i = n - 1; i >= 1; i--) {
      dp[i - 1] = dp[i] / a[i];
    }
    double ans = 0;
    for(int i = 0; i < n; i++) {
      ans += dp[i];
    }
    int an = (int) (ans + .5);
    printf("%d\n", an);
    scanf("%d", &n);
  }
  return 0;
}
