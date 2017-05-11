#include <bits/stdc++.h>

using namespace std;

const int N = 300;

char s[N][N];

int main() {
  int k;
  scanf("%d", &k);
  if (k == 0) {
    puts("Kosong bang");
    return 0;
  }
  int n = 2 * k - 1;
  for (int i = 0; i < n; i++) {
    if (i % 2) continue;
    int d = min(i, n - 1 - i);
    char c;
    if ((d / 2) % 2 == 0) {
      c = 'x';
    } else {
      c = 'o';
    }
    if (i < k) {
      int x = k - 1;
      int y = i;
      while (y < k) {
        s[x][y] = c;
        x++;
        y++;
      }
    } else {
      int x = k - 1;
      int y = i;
      while (y >= k - 1) {
        s[x][y] = c;
        x--;
        y--;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j]) printf("%c", s[i][j]);
      else printf(" ");
    }
    printf("\n");
  }

  return 0;
}
