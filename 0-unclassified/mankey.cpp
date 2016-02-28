#include <bits/stdc++.h>

using namespace std;

string str[] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
int len[] = {3, 3, 3, 3, 3, 4, 3, 4};

char s[1005];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    scanf("%s", s);
    int n = strlen(s);
    printf("Case #%d:", tt);
    for(int i = 0; i < n; i++) {
      for(int k = 0; k < 8; k++) {
        bool ada = 0;
        for(int j = 0; j < len[k]; j++) {
          if(s[i] == str[k][j]) {
            ada = 1;
          }
        }
        if(ada) {
          printf(" ");
          for(int j = 0; j < len[k]; j++) {
            printf("%d", k + 2);
            if(s[i] == str[k][j]) {
              break;
            }
          }
          break;
        }
      }
    }
    printf("\n");
  }
  
  return 0;
}
