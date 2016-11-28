#include <bits/stdc++.h>

using namespace std;

int nim[10][10][10];

int main() {
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      for (int k = 1; k < 10; k++) {
        set<int> s;
        for (int l = 0; l < i; l++) {
          for (int m = 0; m < j; m++) {
            for (int n = 0; n < k; n++) {
              s.insert(nim[l][m][n]);
            }
          }
        }
        for (int l = 0; l <= 1000; l++) {
          if (!s.count(l)) {
            nim[i][j][k] = l;
            break;
          }
        }
        printf("%d %d %d: %d\n", i, j, k, nim[i][j][k]);
      }
    }
  }

  return 0;
}
