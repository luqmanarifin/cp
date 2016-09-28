#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int a[N][N];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> even, odd;
  for (int i = 1; i <= n*n; i++) {
    if (i % 2) {
      odd.push_back(i);
    } else {
      even.push_back(i);
    }
  }
  int p = 0;
  for (int i = 0; i < n; i++) {
    int b = abs(n / 2 - i);
    for (int j = b; j < n - b; j++) {
      //printf("%d %d\n", i, j);
      a[i][j] = odd[p];
      p++;
    }
  }
  p = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0) {
        a[i][j] = even[p];
        p++;
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
