#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    int d = 0, g = 1;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        d += (s[i] == '1');
      } else if (s[i] != s[i-1]) {
        d++;
      }
      if (i > 0 && s[i] != s[i-1]) {
        g++;
      }
    }
    if (g == 1) {

    } else if (g == 2) {
      if (s[0] == '0') {

      } else {
        d = max(0, d - 1);
      }
    } else if (g == 3) {
      if (s[0] == '0') {
        d = max(0, d - 1);
      } else {
        d = max(0, d - 2);
      }
    } else {
      d = max(0, d - 2);
    }
    printf("%d\n", n + d);
  }

  return 0;
}
