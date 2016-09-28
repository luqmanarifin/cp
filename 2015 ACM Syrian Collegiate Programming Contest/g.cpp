#include <bits/stdc++.h>

using namespace std;

char s[5][305];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 3; i++) {
      scanf("%s", s[i]);
    }
    int pol = 0;
    for (int t = 0; t < n; t++) {
      int cur = 0;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (s[i][t * 3 + j] == '*') {
            cur++;
          }
        }
      }
      pol = max(pol, cur);
    }
    printf("%d\n", pol * 4);
  }
  
  return 0;
}
