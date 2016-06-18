#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int a[N][N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  k--;
  int id = n * n;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    for(int j = n - 1; j >= k; j--) {
      a[i][j] = id--;
      if(j == k) {
        sum += a[i][j];
      }
    }
  }
  id = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(a[i][j] == 0) {
        a[i][j] = ++id;
      }
    }
  }
  printf("%d\n", sum);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
