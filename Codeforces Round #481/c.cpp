#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N], s[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    s[i] = s[i-1] + a[i];
  }
  while (m--) {
    long long v;
    scanf("%lld", &v);
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (s[mid] < v) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    printf("%d %lld\n", l, v - s[l-1]);
  }

  return 0;
}
