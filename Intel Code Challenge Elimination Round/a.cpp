#include <bits/stdc++.h>

using namespace std;

int main() {
  int k, a, b;
  scanf("%d %d:%d", &k, &a, &b);
  int ans = 1e9;
  int ai = a / 10;
  int aj = a % 10;
  int bi = b / 10;
  int bj = b % 10;
  int p = -1, q = -1;
  if (k == 12) {
    for (int i = 1; i <= 12; i++) {
      for (int j = 0; j < 60; j++) {
        int aii = i / 10;
        int ajj = i % 10;
        int bii = j / 10;
        int bjj = j % 10;
        int cur = (ai != aii) + (aj != ajj) + (bi != bii) + (bj != bjj);
        if (cur < ans) {
          ans = cur;
          p = i;
          q = j;
        }
      }
    }
  } else {
    for (int i = 0; i < 24; i++) {
      for (int j = 0; j < 60; j++) {
        int aii = i / 10;
        int ajj = i % 10;
        int bii = j / 10;
        int bjj = j % 10;
        int cur = (ai != aii) + (aj != ajj) + (bi != bii) + (bj != bjj);
        if (cur < ans) {
          ans = cur;
          p = i;
          q = j;
        }
      }
    }
  }
  printf("%.2d:%.2d\n", p, q);
  return 0;
}
