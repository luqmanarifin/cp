#include <bits/stdc++.h>

using namespace std;

char s[5];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    for (char c = 'a'; c <= 'h'; c++) {
      if (c != s[0]) {
        printf("%c%c\n", c, s[1]);
      } 
    }
    for (char c = '1'; c <= '8'; c++) {
      if (c != s[1]) {
        printf("%c%c\n", s[0], c);
      }
    }
  }

  return 0;
}
