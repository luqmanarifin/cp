
#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const long long inf = 1e18;

long long a[N];

long long solve(int l, int r, long long h) {
  if (l == r) return 1;
  long long mini = inf;
  for (int i = l; i <= r; i++) mini = min(mini, a[i]);
  long long cur = mini - h;
  for (int i = l; i <= r; i++) {
    if (a[i] == mini) continue;
    int j = i;
    while (j + 1 <= r && a[j + 1] != mini) j++;
    cur += solve(i, j, mini);
    i = j;
  }
  return min(cur, r - l + 1LL);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  printf("%lld\n", solve(0, n - 1, 0));
  return 0;
}
