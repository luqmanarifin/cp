#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N], b[N], h[N][N], ans[N][N];
int n, m;

int main() {
  int v;
  scanf("%d %d %d", &n, &m, &v);
  for (int i = 0; i < m; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) scanf("%d", b + i);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &h[i][j]);
    }  
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (h[i][j] == 0) continue;
      ans[i][j] = min(a[j], b[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}
