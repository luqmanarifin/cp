#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%I64d", a + i);
  for (int i = 1; i <= n; i++) a[i] += a[i - 1];
  double ans = 0;
  int cnt = 0;
  for (int i = k; i <= n; i++) {
    cnt++;
    ans += a[i] - a[i - k];
  }
  printf("%.15f\n", ans / cnt);
  return 0;
}
