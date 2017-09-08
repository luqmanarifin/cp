#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const long long inf = 1e18;

long long take[N];
int pt[N];
long long a[N], s[N];

long long sum(int l, int r) {
  return (r? s[r - 1] : 0) - (l? s[l - 1] : 0);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d", a + i);
  for (int i = 0; i < N; i++) {
    if (i) s[i] = s[i - 1];
    s[i] += a[i];
  }
  fill(take, take + N, -inf);
  for (int i = 0; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      long long cur = sum(i, j) - sum(j, n);
      if (cur > take[i]) {
        take[i] = cur;
        pt[i] = j;
      }
    }
  }
  long long ans = -inf;
  int p, q, r;
  for (int i = 0; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      long long cur = sum(0, i) - sum(i, j) + take[j];
      if (cur > ans) {
        ans = cur;
        p = i;
        q = j;
        r = pt[j];
      }
    }
  }
  printf("%d %d %d\n", p, q, r);
  return 0;
}
