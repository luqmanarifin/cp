#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n; char c;
    scanf("%d %c %s", &n, &c, s + 1);
    bool same = 1;
    for (int i = 1; i <= n; i++) {
      if (s[i] != c) same = 0;
    }
    if (same) {
      printf("0\n");
      continue;
    }
    bool found = 0;
    for (int i = 1; i <= n; i++) {
      bool good = 1;
      for (int j = i; j <= n; j += i) {
        if (s[j] != c) {
          good = 0;
          break;
        }
      }
      if (good) {
        printf("1\n%d\n", i);
        found = 1;
        break;
      }
    }
    if (found) continue;
    printf("2\n%d %d\n", n - 1, n);
  }

  return 0;
}
