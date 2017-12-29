#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int MAGIC = 450;
const int MAX = 105;

int par[MAGIC][MAX], di[MAGIC][MAX], push[MAGIC];
int a[N], n, be[MAX], asli[MAX];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r, x, y;
    scanf("%d %d %d %d", &l, &r, &x, &y);
    l--; r--;
    for (int i = l; i <= r; i++) if (a[i] == x) a[i] = y;
  }
  for (int i = 0; i < n; i++) printf("%d ", a[i]);

  return 0;
}
