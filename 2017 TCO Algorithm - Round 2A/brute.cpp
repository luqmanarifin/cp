#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int a[N][N];

int main() {
  a[0][0] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      for (int k = 1; k <= i; k++) {
        for (int l = 1; l <= j; l++) {
          if (a[i-k][j-l] && __gcd(k, l) != 1) {
            a[i][j] = 1;
          }          
        }
      }
      if (a[i][j]) printf("%d %d\n", i, j);
    }
  }

  return 0;
}
