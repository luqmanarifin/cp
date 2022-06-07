#include <bits/stdc++.h>

using namespace std;

char s[50][50];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("Case #%d:\n", tt);
    for (int i = 0; i < 2 * n + 1; i++) {
      for (int j = 0; j < 2 * m + 1; j++) {
        char c;
        if (i % 2) {
          if (j % 2) {
            c = '.';
          } else {
            c = '|';
          }
        } else {
          if (j % 2) {
            c = '-';
          } else {
            c = '+';
          }
        }
        if (i <= 1 && j <= 1) c = '.';
        printf("%c", c);
      }
      printf("\n");
    }
  }

  return 0;
}
