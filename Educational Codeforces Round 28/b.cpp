#include <bits/stdc++.h>

using namespace std;

const int N = 50;

long long t[N];

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  long long tot = 0;
  for (int i = 0; i < k; i++) {
    scanf("%I64d", t + i);
    tot += t[i];
  }
  sort(t, t + k);
  long long ans = 0;
  for (int all = 0; all <= n; all++) {
    if (m >= tot * all) {
      long long cur = all + k * all;
      long long rem = m - tot * all;
      for (int i = 0; i < k; i++) {
        long long can = n - all;
        long long del = min(can, rem / t[i]);
        rem -= del * t[i];
        cur += del;
      }
      ans = max(ans, cur);
    }
  }
  cout << ans << endl;
  return 0;
}
