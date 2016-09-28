#include <bits/stdc++.h>

using namespace std;

const int N = 300;

int a[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
      for (int j = 0; j < 2 * n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        sum += max(max(a[i][j], a[2*n-1-i][j]), max(a[i][2*n-1-j], a[2*n-1-i][2*n-1-j]));
      }
    }
    printf("%d\n", sum);
  }

  return 0;
}
