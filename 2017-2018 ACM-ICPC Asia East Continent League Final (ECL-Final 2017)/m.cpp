
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], cost[N];

int main() {
  int now = 48;
  for (int j = 8, p = 1; j >= 1; j /= 2, p++) {
    for (int i = 1; i <= j; i++) {
      a[now + i] = p;
    }
    now += j;
  }
  
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < 5; i++) scanf("%d", cost + i);
    int q;
    scanf("%d", &q);
    long long ans = 0;
    while (q--) {
      int v;
      scanf("%d", &v);
      ans += cost[a[v]];
    }
    printf("Case #%d: %lld\n", tt, ans * 10000);
  }

  return 0;
}
