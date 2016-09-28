#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    bool done = 0;
    for (int i = 0; i < n; i++) {
      int j = n - 1 - i;
      if (s[i] != '.' && s[j] != '.' && s[i] != s[j]) {
        puts("-1");
        done = 1;
        break;
      }
      if (s[i] == '.' && s[j] != '.') {
        s[i] = s[j];
      }
      if (s[i] != '.' && s[j] == '.') {
        s[j] = s[i];
      }
      if (s[i] == '.' && s[j] == '.') {
        s[i] = s[j] = 'a';
      }
    }
    if (!done) printf("%s\n", s);
  }

  return 0;
}
