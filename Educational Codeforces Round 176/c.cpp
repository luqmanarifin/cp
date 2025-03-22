#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N], cnt[N], s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d", a + i);
    for (int i = 0; i <= n; i++) cnt[i] = s[i] = 0;
    for (int i = 0; i < m; i++) {
      int k = min((long long)n - 1, a[i]);
      cnt[k]++;
    }
    long long sum = 0;
    for (int i = n - 1; i >= 1; i--) {
      sum += cnt[i];
      s[i] = s[i + 1] + sum;
    }
    long long ans = 0;
    for (int i = 0; i < m; i++) {
      int now = min((long long)n - 1, a[i]);
      int other = n - now;
      ans += s[other];
      if (other <= now) {
        ans -= now - other + 1;
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}
