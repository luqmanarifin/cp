#include <bits/stdc++.h>

using namespace std;

char s[700][700];
int dx[] = {1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1, 1, 0, 1, 1};
int dy[] = {1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1};

void warnai(int x, int y, int ping) {
  for(int d = 0; d < 16; d++) {
    for(int i = 0; i < ping; i++) {
      x += dx[d];
      y += dy[d];
      s[x][y] = '1';
    }
  }
}

int main() {
  int n, x1, y1, x2, y2;
  scanf("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);
  int c = 3 * n;
  for(int i = 0; i < 700; i++) {
    for(int j = 0; j < 700; j++) {
      s[i][j] = '.';
    }
  }
  for(int i = 1; i <= n; i++) {
    warnai(c, c - i * 3, i);
  }
  int size = 6 * n + 1;
  for(int i = x1; i <= x2; i++) {
    for(int j = y1; j <= y2; j++) {
      printf("%c", s[i][j]);
    }
    printf("\n");
  }
  return 0;
}
