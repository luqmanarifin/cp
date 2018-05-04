#include <bits/stdc++.h>

using namespace std;

const int N = 40;

char s[N][N];

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    set<char> all;
    for (int i = 0; i < n; i++) {
      set<char> a, b;
      for (int j = 0; j < n; j++) {
        all.insert(s[i][j]);
        a.insert(s[i][j]);
        b.insert(s[j][i]);
      }
      if (a.size() != n || b.size() != n) {
        puts("No");
        goto hell;
      }
    }
    if (all.size() != n) {
      puts("No");
      goto hell;
    }
    for (int i = 1; i < n; i++) {
      if (s[0][i-1] > s[0][i]) {
        puts("Not Reduced");
        goto hell;
      }
      if (s[i-1][0] > s[i][0]) {
        puts("Not Reduced");
        goto hell;
      }
    }
    puts("Reduced");
    hell:;
  }
  return 0;
}
