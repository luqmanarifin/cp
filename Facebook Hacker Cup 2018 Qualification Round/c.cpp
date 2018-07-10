#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

char s[N];
int n;

bool ok(int p) {
  for (int i = p; i < n; i++) {
    if (s[i] != s[i-p]) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%s", s);
    n = strlen(s);
    bool ada = 0;
    printf("Case #%d: ", tt);
    for (int i = 1; i < n; i++) {
      if (s[i] == s[0]) {
        if (ok(i)) {
          ada = 1;
          for (int j = 0; j < i; j++) printf("%c", s[j]);
          for (int j = 0; j < n; j++) printf("%c", s[j]);
          printf("\n");
          break;
        }
      }
    }
    if (!ada) printf("Impossible\n");
    fprintf(stderr, "%d done!\n", tt);
  }

  return 0;
}
