#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    bool can = (2 * k >= n);
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j + 1 < n && a[j + 1] == a[j]) j++;
      int cnt = j - i + 1;
      if (cnt > 2) {
        can = 0;
      }
      i = j;
    }
    printf("Case #%d: %s\n", tt, can? "YES" : "NO");
  }

  return 0;
}
