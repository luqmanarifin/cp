#include <bits/stdc++.h>

using namespace std;

char s[5][5];

int main() {
  for(int i = 0; i < 4; i++) scanf("%s", s[i]);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      int dot = 0;
      for(int k = i; k <= i + 1; k++) {
        for(int l = j; l <= j + 1; l++) {
          if(s[k][l] == '.') dot++;
        }
      }
      if(dot != 2) {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}