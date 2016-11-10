#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char s[N][N];

int main() {
  int n;
  scanf("%d", &n);
  int tt = 0;
  while (n) {
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - i; j++) {
        s[i][j] -= '0';
      }
    }
    for (int len = 0; len < n - 1; len++) {
      for (int i = 0; i < n; i++) {
        int j = len - i;
        if (j < 0) break;
        if (s[i][j]) {
          s[i][j] ^= 1;
          s[i+1][j] ^= 1;
          s[i][j+1] ^= 1;
        }
      }
    }
    for (int i = 0; i + 2 < n; i++) {
      int j = n - 1 - i;
      if (s[i][j]) {
        s[i][j] ^= 1;
        s[i+1][j-1] ^= 1;
        s[i+2][j-2] ^= 1;
      }
    }
    bool all = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - i; j++) {
        if (s[i][j]) {
          all = 0;
        }
        //printf("%d", s[i][j]);
      }
      //printf("\n");
    }
    if (all) {
      printf("Triangle %d can be filled.\n", ++tt);
    } else {
      printf("Triangle %d cannot be filled.\n", ++tt);
    }
    scanf("%d", &n);
  }

  return 0;
}
