#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long w[N], s[N], f[N], tw[N], ts[N], tf[N];
long long cur[N], answ[N];
long long ans[N];

int main() {
  int n; long long k;
  scanf("%d %I64d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%I64d", f + i);
  for (int i = 0; i < n; i++) scanf("%I64d", w + i);
  for (int i = 0; i < n; i++) {
    s[i] = w[i];
    cur[i] = i;
    answ[i] = 1e9;
  }
  for (long long mask = 1; mask <= k; mask <<= 1) {
    if (mask & k) {
      for (int i = 0; i < n; i++) {
        ans[i] += s[cur[i]];
        answ[i] = min(answ[i], w[cur[i]]);
        cur[i] = f[cur[i]];
      }
    }
    //for (int i = 0; i < n; i++) printf("%I64d ", w[i]); printf("\n");
    for (int i = 0; i < n; i++) {
      ts[i] = s[i] + s[f[i]];
      tw[i] = min(w[i], w[f[i]]);
      tf[i] = f[f[i]];
    }
    for (int i = 0; i < n; i++) {
      s[i] = ts[i];
      w[i] = tw[i];
      f[i] = tf[i];
    }
  }
  for (int i = 0; i < n; i++) printf("%I64d %d\n", ans[i], answ[i]);
  return 0;
}
