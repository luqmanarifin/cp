#include <bits/stdc++.h>

using namespace std;

const int N = 10;

char s[N][N];
int n = 8;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < n;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        bool good = 1;
        for (int k = 0; k < n; k++) {
          for (int l = 0; l < n; l++) {
            int di = abs(k - i);
            int dj = abs(l - j);
            if (di != dj) {
              if (s[k][l] != '.') {
                good = 0;
              }
            } else {
              if (s[k][l] != '#') {
                good = 0;
              }
            }
          }
        }
        if (good) {
          printf("%d %d\n", i + 1, j + 1);
          goto NEXT;
        }
      }
    }
    NEXT:;
  }

  return 0;
}
