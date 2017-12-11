#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int c = (i + j) % 2;
        if (c) {
          if (s[i][j] == 'R') {
            a += 5;
          } else {
            b += 3;
          }
        } else {
          if (s[i][j] == 'G') {
            a += 3;
          } else {
            b += 5;
          }
        }
      }
    }
    printf("%d\n", min(a, b));
  }

  return 0;
}
