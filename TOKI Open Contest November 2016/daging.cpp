#include <bits/stdc++.h>

using namespace std;

char s[100];

int main() {
  int n;
  scanf("%d", &n);
  int now = 0, a = 0, b = 0;
  for (int i = 1; i <= n; i++) {
    if (now == 0) {
      printf("%d SAITAMA\n", i);
      fflush(stdout);
      
      scanf("%s", s);
      int len = strlen(s);
      if (len == 7) {
        now = 1;
        a++;
      } else if (len == 4) {
        now = 0;
        b++;
      }
    } else if (now == 1) {
      printf("%d GENOS\n", i);
      fflush(stdout);
      
      scanf("%s", s);
      int len = strlen(s);
      if (len == 4) {
        now = 0;
        b++;
      } else {
        a++;
      }
    } else {
      printf("%d SAITAMA\n", i);
      fflush(stdout);
      
      scanf("%s", s);
      int len = strlen(s);
      if (len == 4) {
        now = 0;
        a++;
      } else {
        b++;
      }
    }
  }
  printf("%d %d\n", a, b);
  fflush(stdout);
  return 0;
}
