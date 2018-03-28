#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int ans[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while (m--) {
    int p, a, b, c, d;
    scanf("%d %d %d %d %d", &p, &a, &b, &c, &d);
    ans[a][b] ^= p;
    ans[c+1][b] ^= p;
    ans[a][d+1] ^= p;
    ans[c+1][d+1] ^= p;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans[i][j] ^= ans[i-1][j-1];
      ans[i][j] ^= ans[i][j-1];
      ans[i][j] ^= ans[i-1][j];
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }

  return 0;
}
