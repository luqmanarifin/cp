
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], tmp[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  while (q--) {
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    if (t == 1) {
      a[l] = r;
    } else {
      for (int i = l; i <= r; i++) tmp[i-l] = a[i];
      int sz = r - l + 1;
      sort(tmp, tmp + sz);
      bool found = 0;
      for (int i = sz - 2; i > 0; i--) {
        if (tmp[i-1] + tmp[i] > tmp[i+1]) {
          printf("%lld\n", (long long) tmp[i-1] + tmp[i] + tmp[i+1]);
          found = 1;
          break;
        }
      }
      if (!found) printf("0\n");
    }
  }

  return 0;
}
