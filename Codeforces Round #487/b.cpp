#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

char s[N];

int main() {
  int n, p;
  scanf("%d %d %s", &n, &p, s);
  bool can = 0;
  for (int i = 0; i < p; i++) {
    set<char> m;
    for (int j = i; j < n; j += p) {
      if (s[j] != '.') {
        m.insert(s[j]);
      }
    }
    if (m.size() == 0) {
      int ada = 0;
      for (int j = i; j < n; j += p) {
        if (s[j] == '.') {
          s[j] = (ada % 2? '0' : '1');
          ada++;
        }
      }
      if (ada > 1) can = 1;
    } else if (m.size() == 1) {
      auto it = *(m.begin());
      char isi = ((it - '0') ^ 1) + '0';
      bool filled = 0;
      for (int j = i; j < n; j += p) {
        if (s[j] == '.') {
          filled = 1;
          s[j] = isi;
        }
      }
      if (filled) can = 1;
    } else {
      can = 1;
      for (int j = i; j < n; j += p) {
        if (s[j] == '.') {
          s[j] = '0';
        }
      }
    }
  }
  if (!can) {
    puts("No");
  } else {
    printf("%s\n", s);
  }
  return 0;
}