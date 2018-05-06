
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], pre[N][40];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    for (int j = 0; j <= 30; j++) {
      if (a[i] & (1 << j)) {
        pre[i][j] = 1;
      }
      pre[i][j] += pre[i-1][j];
    }
  }
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    int ans = 0;
    for (int i = 0; i <= 30; i++) {
      int nyala = pre[r][i] - pre[l-1][i];
      int mati = r - l + 1 - nyala;
      if (mati > nyala) {
        ans |= 1 << i;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
