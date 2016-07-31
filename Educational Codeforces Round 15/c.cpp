#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 5;

int a[N], b[N];
int n, m;

bool can(int t) {
  int now = 0;
  for (int i = 0; i < m && now < n; i++) {
    if (a[now] < b[i] - t) return 0;
    while (now < n && abs(a[now] - b[i]) <= t) now++;
  }
  return now == n;
}

main() {
  scanf("%I64d %I64d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%I64d", a + i);
  for (int i = 0; i < m; i++) scanf("%I64d", b + i);
  int l = 0, r = 2e9;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  printf("%I64d\n", l);
  return 0;
}
