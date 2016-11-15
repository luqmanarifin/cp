#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int a[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int k = n / 2;
    for (int i = 0; i < n; i++) a[k][i] = i + 1;
    for (int i = k - 1; i >= 0; i--) {
      for (int j = 0; j < n; j++) {
        a[i][j] = a[i + 1][(j - 1 + n) % n];
      }
    }
    for (int i = k + 1; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = a[i - 1][(j + 1) % n];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}
