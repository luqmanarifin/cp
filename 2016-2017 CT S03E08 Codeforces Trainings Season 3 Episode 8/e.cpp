#include <bits/stdc++.h>

using namespace std;

const int N = 6;

int a[N], n, sum[1 << N];
double lim;

bool ada;
double where[N], ans;

void dfs(int mask, int lef, double now) {
  if (__builtin_popcount(mask) == 1) {
    where[__builtin_clz(mask) ^ 31] = now;
    if (lef == n - 1) {
      double mini = 1e9, maxi = -1e9;
      for (int i = 0; i < n; i++) {
        mini = min(mini, where[i]);
        maxi = max(maxi, where[i]);
      }
      double cur = maxi - mini;
      //printf("%.15f\n", cur);
      if (cur < lim) {
        ans = max(ans, cur);
        ada = 1;
      }
    }
    return;
  }
  for (int i = ((mask - 1) & mask); i > 0; i = ((i - 1) & mask)) {
    int j = (mask ^ i);
    dfs(i, lef, now - (double) sum[j] / sum[mask]);
    dfs(j, lef + __builtin_popcount(i), now + (double) sum[i] / sum[mask]);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    
    scanf("%lf %d", &lim, &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for (int mask = 0; mask < (1 << n); mask++) {
      sum[mask] = 0;
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
          sum[mask] += a[i];
        }
      }
    }
    
    ans = -1;
    ada = 0;
    dfs((1 << n) - 1, 0, 0);
    
    if (!ada) {
      puts("-1");
    } else {
      printf("%.15f\n", ans);
    }
  }

  return 0;
}
