#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], f[N], g[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) scanf("%d", b + i);
  int id = 0;
  for (int i = 0; i < n; i++) {
    id++;

    int j = i;
    while (j + 1 < n && a[j] % 2 == a[j + 1] % 2) j++;
    for (int k = i; k <= j; k++) f[k] = id;
    i = j;
  }
  for (int i = 0; i < n; i++) {
    id++;

    int j = i;
    while (j + 1 < n && b[j] % 2 == b[j + 1] % 2) j++;
    for (int k = i; k <= j; k++) g[k] = id;
    i = j;
  }
  while (q--) {
    int ra, ca, rb, cb;
    scanf("%d %d %d %d", &ra, &ca, &rb, &cb);
    ra--;
    ca--;
    rb--;
    cb--;
    if (f[ra] == f[rb] && g[ca] == g[cb]) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
