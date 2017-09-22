#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], to[105];
int t[N], l[N], r[N];

int main() {
  int n, q, m;
  scanf("%d %d %d", &n, &q, &m);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= q; i++) scanf("%d %d %d", t + i, l + i, r + i);
  for (int i = 1; i <= m; i++) scanf("%d", to + i);
  for (int i = q; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      if (t[i] == 1) {
        if (l[i] <= to[j] && to[j] <= r[i]) {
          if (to[j] == l[i]) {
            to[j] = r[i];
          } else {
            to[j]--;
          }
        }
      } else {
        if (l[i] <= to[j] && to[j] <= r[i]) {
          int bef = to[j] - l[i];
          int ada = r[i] - l[i];
          to[j] = l[i] + ada - bef;
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) printf("%d ", a[to[i]]); printf("\n");

  return 0;
}
