#include <bits/stdc++.h>

using namespace std;

string s = "aiueo";

char get(int i, int j) {
  return s[(i + j) % 5]; 
}

int main() {
  int k;
  scanf("%d", &k);
  for (int n = 5; n <= k; n++) {
    if (k % n == 0) {
      int m = k / n;
      if (m >= 5) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            printf("%c", get(i, j));
          }
          // printf("\n");
        }
        return 0;
      }
    }
  }
  puts("-1");
  return 0;
}
