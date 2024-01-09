#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];

bool is(char c) {
  return c == 'a' || c == 'e';
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    for (int i = 0; i < n; i++) {
      if (is(s[i]) && i + 2 < n) {
        if (is(s[i + 2])) {
          printf("%c.%c", s[i], s[i+1]);
          i++;
          continue;

        } else if (is(s[i + 3])) {
          printf("%c%c.%c", s[i], s[i+1], s[i+2]);
          i += 2;
          continue;

        }
      }
      printf("%c", s[i]);
    }
    printf("\n");
  }

  return 0;
}
