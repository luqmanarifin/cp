#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][N], tmp[N][N];
int n, m, k;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  scanf("%d", &k);
  for (int i = 0; i < n; i++) m = max(m, (int)strlen(s[i]));
  k /= 90;
  k %= 4;
  while (k--) {
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        tmp[j][n - 1 - i] = s[i][j];
      }
    }
    memset(s, 0, sizeof(s));
    swap(n, m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        s[i][j] = tmp[i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j]) printf("%c", s[i][j]);
      else printf("-");
    }
    printf("\n");
  }
  return 0;
}
