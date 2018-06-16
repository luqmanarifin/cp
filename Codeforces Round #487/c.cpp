#include <bits/stdc++.h>

using namespace std;

const int MAX = 24;
const int N = 105;

int s[N][N];
int a[5];

int main() {
  for (int i = 0; i < 4; i++) scanf("%d", a + i);
  int n = 0, m = 3;
  // dalem c, luar c + 1
  for (int c = 0; c < 4; c++) {
    int ada = a[c] - 1;
    int col = min(MAX, ada);
    int row = 1;
    if (col > 0) {
      row = max(row, ada / col + (ada % col? 1 : 0));
    }
    n += 2 * row + 1;
    m = max(m, col * 2 + 1);
  }
  // puts("itung done");
  int row_now = 0;
  for (int c = 0; c < 4; c++) {
    int ada = a[c] - 1;
    int col = min(MAX, ada);
    int row = 1;
    if (col > 0) {
      row = max(row, ada / col + (ada % col? 1 : 0));
    }

    int dalem = c;
    int luar = (c + 1) % 4;

    for (int i = 0; i < 2 * row + 1; i++) {
      for (int j = 0; j < m; j++) {
        s[row_now + i][j] = luar;
      }
    }
    // 0 -> 1
    // 1 -> 3
    // 2 -> 5
    for (int i = 0; i < row && ada; i++) {
      for (int j = 1; j < m && ada; j += 2) {
        s[row_now + 2 * i + 1][j] = dalem;
        ada--;
      }
    }

    row_now += 2 * row + 1;
  }

  printf("%d %d\n", n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%c", s[i][j] + 'A');
    }
    printf("\n");
  }

  return 0;
}
