#include <bits/stdc++.h>

using namespace std;

const int N = 22;

char s[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      scanf(" %c", &s[i][j]);
    }
  }
  while(1) {
    int best = -1;
    for(int i = 1; i <= n; i++) {
      bool isLine = true;
      for(int j = 1; j <= m; j++) {
        if(s[i][j] == '0') {
          isLine = false;
        }
      }
      if(isLine) {
        for(int j = 1; j <= m; j++) {
          s[i][j] = '0';
        }
        best = max(best, i);
      }
    }
    if(best == -1) break;
    for(int i = best; i >= 1; i--) {
      for(int j = 1; j <= m; j++) {
        if(s[i][j] == '1') {
          int k = i;
          while(s[k+1][j] == '0' && k+1 <= n) {
            k++;
          }
          swap(s[i][j], s[k][j]);
        }
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      printf("%c", s[i][j]);
    }
    printf("\n");
  }
  return 0;
}