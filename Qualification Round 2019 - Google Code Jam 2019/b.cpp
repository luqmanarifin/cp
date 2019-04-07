#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d %s", &n, s);
    n = 2 * n - 2;
    printf("Case #%d: ", tt);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'E') {
        printf("S");
      } else {
        printf("E");
      }
    }
    printf("\n");
  }
  return 0;
}
