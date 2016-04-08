#include <bits/stdc++.h>

using namespace std;

int c[][4] = {
  {0, 2, 5, 4},
  {0, 1, 5, 3},
  {1, 2, 3, 4}
};

char s[15][15], a[15], b[15];

int main() {
  scanf("%s %s", a, b);
  int n = strlen(a);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  double ans = 1;
  for(int i = 0; i < n; i++) {
    int now = 0, all = 0;
    for(int t = 0; t < 6; t++) {
      if(a[i] != s[i][t]) continue;
      for(int j = 0; j < 3; j++) {
        bool from = 0, to = 0;
        for(int k = 0; k < 4; k++) {
          if(t == c[j][k]) {
            from = 1;
          }
          if(b[i] == s[i][c[j][k]]) {
            to = 1;
          }
        }
        if(from) {
          all++;
          if(to) {
            now++;
          }
        }
      }
    }
    ans *= (double) now / all;
  }
  printf("%.15f\n", ans);
  return 0;
}