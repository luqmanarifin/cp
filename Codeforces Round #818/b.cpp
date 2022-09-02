#include <bits/stdc++.h>

using namespace std;

const int N = 505;

char s[N][N];
int n;

void fill(int x, int y) {
  for (int i = 0; i < n; i++) {
    s[(x + i) % n][(y + i) % n] = 'X';
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(s, 0, sizeof(s));

    int k, r, c;
    scanf("%d %d %d %d", &n, &k, &r, &c);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        s[i][j] = '.';
      }
    }
    r--; c--;
    for (int i = r; i < r + n; i += k) {
      fill(i % n, c);
    }
    for (int i = 0; i < n; i++) printf("%s\n", s[i]);
  }

  return 0;
}
