#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int a[N][N], b[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]); 
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &b[i][j]); 
    }
  }
  for (int i = 0; i + 1 < n; i++) {
    for (int j = 0; j + 1 < m; j++) {
      if (a[i][j] != b[i][j]) {
        a[i][j] ^= 1;
        a[i+1][j] ^= 1;
        a[i][j+1] ^= 1;
        a[i+1][j+1] ^= 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != b[i][j]) {
        puts("No");
        return 0;
      }
    }
  }
  puts("Yes");
  return 0;
}
