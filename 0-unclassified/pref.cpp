#include <bits/stdc++.h>

using namespace std;

char s[5][105];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    int len = 205;
    for(int i = 0; i < n; i++) {
      scanf("%s", s[i]);
      len = min(len, (int) strlen(s[i]));
    }
    printf("Case #%d: ", tt);
    for(int j = 0; j < len; j++) {
      bool all = 1;
      for(int i = 1; i < n; i++) {
        if(s[i][j] != s[0][j]) {
          all = 0;
          break;
        }
      }
      if(!all) break;
      printf("%c", s[0][j]);
    }
    printf("\n");
  }
  
  return 0;
}
