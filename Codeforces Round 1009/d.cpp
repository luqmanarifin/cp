#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int x[N], r[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", x + i);
    for (int i = 0; i < n; i++) scanf("%d", r + i);

    map<int, bool> ada;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
      for (int j = x[i] - r[i]; j <= x[i] + r[i]; j++) {
        ada[j] = 1;
        long long d = abs(j - x[i]);
        long long v = 1LL * r[i] * r[i] - d * d;
        h[j] = max(h[j], (int) sqrt(v));
      }
    }
    long long ans = 0;
    for (auto key : ada) {
      // printf("oke gas %d\n", key.first);
      ans += h[key.first] * 2 + 1;
    }
    printf("%lld\n", ans);
  }

  return 0;
}
