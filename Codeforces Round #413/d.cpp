#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 5;
const long long magic = 40;

long long a, b, h, w, n;
int d[magic + 5][N], v[N];

long long upd(int& at, int val) {
  at = max(at, val);
}

int main() {
  scanf("%lld %lld %lld %lld %lld", &a, &b, &h, &w, &n);
  for (int i = 0; i < n; i++) scanf("%d", v + i);
  sort(v, v + n);
  reverse(v, v + n);
  d[0][h] = w;
  for (int i = 0; i <= min(n, magic); i++) {
    for (int k = 0; k < N; k++) {
      if (k >= a && d[i][k] >= b) {
        printf("%d\n", i);
        return 0;
      }
      if (k >= b && d[i][k] >= a) {
        printf("%d\n", i);
        return 0;
      }
      int to = min(N - 1, 1LL * k * v[i]);
      upd(d[i+1][to], d[i][k]);
      
      to = min(N - 1, 1LL * d[i][k] * v[i]);
      upd(d[i+1][k], to);
    }
  }
  puts("-1");
  return 0;
}
