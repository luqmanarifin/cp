#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][N];

int main() {
  int n;
  char c, d;
  scanf("%d %c %c", &n, &c, &d);
  for(int i = 0; i < n; i++) {
    s[i][0] = s[i][n - 1] = s[0][i] = s[n - 1][i] = d;
  }
  if(n % 2 == 1) {
    s[n / 2][n / 2] = '*';
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(s[i][j] == 0) {
        s[i][j] = c;
      }
    }
    printf("%s\n", s[i]);
  }
  return 0;
}
