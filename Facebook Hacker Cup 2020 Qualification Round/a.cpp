#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int d[N][N];
char in[N], ou[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d %s %s", &n, in, ou);
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++) {
      d[i][i] = 1;
      if (i - 1 >= 0) d[i][i-1] = 1;
      if (i + 1 < n) d[i][i+1] = 1;
    }
    for (int i = 0; i < n; i++) {
      if (i - 1 >= 0) {
        if (ou[i] == 'N') d[i][i-1] = 0;
        if (in[i] == 'N') d[i-1][i] = 0;
      }
      if (i + 1 < n) {
        if (ou[i] == 'N') d[i][i+1] = 0;
        if (in[i] == 'N') d[i+1][i] = 0;
      }
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (d[i][k] && d[k][j]) {
            d[i][j] = 1;
          }
        }
      }
    }
    printf("Case #%d:\n", tt);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%c", d[i][j]? 'Y' : 'N');
      }
      printf("\n");
    }
  }

  return 0;
}
