#include <bits/stdc++.h>

using namespace std;

char s[1005];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
      printf("READ %d\n", i);
      fflush(stdout);
      scanf("%s", s);
      if (s[0] == 'f') {
        printf("OUTPUT %d\n", i - 1);
        fflush(stdout);
        break;
      }
    }
  }
  return 0;
}
