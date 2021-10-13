#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int a[N], n, k;

bool can(int mid) {
  int pos = 0;
  for (int i = 0; i < mid; i++) {
    int idx = k - i - 1;
    if (pos >= a[idx]) return 0;
    pos += n - a[idx];
  }
  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
      scanf("%d", a + i);
    }
    sort(a, a + k);
    int l = 0, r = k;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (can(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    printf("%d\n", l);
  }
  return 0;
}
