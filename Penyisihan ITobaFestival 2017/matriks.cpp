#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char s[N][N];
char a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(s, 0, sizeof(s));
    scanf("%s", a);
    int n = strlen(a);
    int mid = (n - 1) / 2;
    for (int i = 0; i < (n + 1) / 2; i++) {
      for (int j = 0; j <= i; j++) {
        s[mid-i][i-j] = a[i];
        s[mid+i][i-j] = a[i];
        s[mid+j][i] = a[i];
        s[mid-j][i] = a[i];
      }
    }
    for (int i = n - 1; i >= (n + 1) / 2 - 1; i--) {
      int k = n - 1 - i;
      for (int j = 0; j <= k; j++) {
        s[mid-k][n-1-j] = a[i];
        s[mid+k][n-1-j] = a[i];
        s[mid+j][n-1-k] = a[i];
        s[mid-j][n-1-k] = a[i];
      }
    }
    int m = n;
    n = (m % 2 == 0? m - 1 : m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%c ", s[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}
