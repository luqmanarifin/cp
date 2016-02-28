#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N][N];

int main() {
  for(int len = 1; len <= 9; len++) {
    int n = (1 << (len - 1));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        a[i + n][j] = (a[i][j] ^ 1);
        a[i][j + n] = (a[i][j] ^ 1);
        a[i + n][j + n] = (a[i][j] ^ 1);
      }
    }
  }
  int k;
  scanf("%d", &k);
  int n = (1 << k);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(a[i][j]) printf("+");
      else printf("*");
    }
    printf("\n");
  }
  return 0;
}
