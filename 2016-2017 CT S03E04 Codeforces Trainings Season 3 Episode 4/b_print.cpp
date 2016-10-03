#include <bits/stdc++.h>

using namespace std;

int a[105][1005];
int b[105], e[105];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    for (int i = 0; i < n; i++) {
      sort(a[i], a[i] + m);
      for (int j = 0; j < m; j++) printf("%d ", a[i][j]); printf("\n");
    }
    printf("\n");
  }

  return 0;
}
