#include <bits/stdc++.h>

using namespace std;

char s[55][55];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      s[i][j] = '.';
    }
  }
  for(int i = 0; i < n; i++) {
    if(i % 2 == 0) {
      for(int j = 0; j < m; j++) {
        s[i][j] = '#';
      }
    } else {
      if(i / 2 % 2 == 0) {
        s[i][m - 1] = '#';
      } else {
        s[i][0] = '#';
      }
    }
  }
  for(int i = 0; i < n; i++) {
    printf("%s\n", s[i]);
  }  
  
  return 0;
}