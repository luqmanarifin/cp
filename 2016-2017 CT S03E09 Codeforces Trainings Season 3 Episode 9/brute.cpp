#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int a[3], b[3];

int main() { 
  for (int n = 4; n < N; n++) {
    int ans = 0;
    for (int i = 0; i < n * n; i++) {
      for (int j = i + 1; j < n * n; j++) {
        for (int k = j + 1; k < n * n; k++) {
          a[0] = i / n;
          b[0] = i % n;
          a[1] = j / n;
          b[1] = j % n;
          a[2] = k / n;
          b[2] = k % n;
          int can = 1;
          for (int l = 0; l < 3; l++) {
            for (int m = l + 1; m < 3; m++) {
              can &= a[l] != a[m];
              can &= b[l] != b[m];
              can &= abs(a[l] - a[m]) != abs(b[l] - b[m]);
            }
          }
          ans += can;
        }
      }
    }
    printf("%d,", ans);
  }
  
  return 0;
}
