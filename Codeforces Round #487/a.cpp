#include <bits/stdc++.h>

using namespace std;

char s[105];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  bool ada = 0;
  for (int i = 1; i + 1 < n; i++) {
    set<char> m;
    for (int j = -1; j <= 1; j++) {
      m.insert(s[j + i]);
    }
    bool all = 1;
    for (int c = 'A'; c <= 'C'; c++) {
      if (!m.count(c)) {
        all = 0;
      }
    }
    if (all) ada = 1;
  }
  puts(ada? "Yes" : "No");
  return 0;
}
