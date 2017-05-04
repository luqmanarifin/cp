#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N][N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (k > n * n) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (i == j) {
        if (k) {
          a[i][i] = 1;
          k--;
        }
      } else {
        if (k >= 2) {
          a[i][j] = a[j][i] = 1;
          k -= 2;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}
