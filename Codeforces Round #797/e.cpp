#include <bits/stdc++.h>

using namespace std;

const int K = 1005;
const int N = 2e5 + 5;

int cnt[K], a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) cnt[i] = 0;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      ans += a[i] / k;
      cnt[a[i] % k]++;
    }
    long long free = 0;
    for (int i = 1; i < k - i; i++) {
      free += cnt[k - i];
      long long here = min((long long) cnt[i], free);
      ans += here;
      free -= here;
    }
    if (k % 2 == 0) free += cnt[k / 2];
    ans += free / 2;
    printf("%lld\n", ans);
  }

  return 0;
}
