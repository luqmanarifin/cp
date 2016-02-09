#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char s[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      s[i][j] = '.';
    }
  }
  for(int i = 0; i < n; i += 2) {
    for(int j = 0; j < m; j++) {
      s[i][j] = '#';
    }
  }
  for(int i = 1; i < n; i += 2) {
    if(i % 4 == 1) {
      s[i][m - 1] = '#';
    } else {
      s[i][0] = '#';
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      printf("%c", s[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
