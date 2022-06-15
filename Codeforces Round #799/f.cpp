#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int D = 10;

int a[N];
bool done[N][10][4];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      for (int j = 0; j < D; j++) {
        for (int k = 0; k <= 3; k++) {
          done[i][j][k] = 0;
        }
      }
    }
    done[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < D; j++) {
        for (int k = 0; k < 3; k++) {
          if (done[i-1][j][k]) {
            done[i][(j + a[i]) % D][k + 1] = 1;
          }
        }
        for (int k = 0; k <= 3; k++) {
          if (done[i-1][j][k]) {
            done[i][j][k] = 1;
          }
        }
      }
    }
    puts(done[n][3][3]? "YES" : "NO");
  }
  return 0;
}
