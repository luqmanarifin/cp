#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N], b[N], l[N], r[N], xa[N], xb[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n; long long m;
    scanf("%d %lld", &n, &m);
    long long sum = 0, sum_l = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld %lld", a + i, b + i);
      long long min_a = min(m, a[i]);
      long long min_b = min(m, b[i]);
      l[i] = (m - min_a) - min_a;
      r[i] = min_b - (m - min_b);
      sum_l += l[i];
      sum += a[i] - b[i];
    }
    sum += sum_l;
    for (int i = 0; i < n; i++) {
      long long available = r[i] - l[i];
      long long need = max(-sum, 0LL);
      long long give = min(available, need);
      if (give % 2) give--;
      long long at = l[i] + give;
      xb[i] = (at + m) / 2;
      xa[i] = m - xb[i];
      sum += give;
    }
    printf("%lld\n", abs(sum));
    for (int i = 0; i < n; i++) {
      printf("%lld %lld\n", xa[i], xb[i]);
    }
  }

  return 0;
}
