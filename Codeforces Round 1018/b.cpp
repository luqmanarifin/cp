#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    for (int i = 0; i < n; i++) scanf("%lld", b + i);
    vector<pair<long long, long long>> p;
    for (int i = 0; i < n; i++) {
      int l = min(a[i], b[i]);
      int r = max(a[i], b[i]);
      p.emplace_back(l, r);
    }
    sort(p.begin(), p.end());
    long long ans = 0;
    for (int i = 1; i < k; i++) {
      ans += p[n - i].first + p[n - i].second;
    }
    for (int i = k; i <= n; i++) {
      ans += p[n - i].second;
    }
    printf("%lld\n", ans + 1);
  }

  return 0;
}
