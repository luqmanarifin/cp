#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int nim[N];
char s[N];

int main() {
  for (int i = 1; i < N; i++) {
    set<int> s;
    s.insert(nim[i - 1]);
    if (i >= 3) {
      s.insert(nim[i - 2]);
    }
    for (int j = 0; j < N; j++) {
      if (!s.count(j)) {
        nim[i] = j;
        break;
      }
    }
  }
  scanf("%s", s);
  int n = strlen(s), dif = 0;
  for (int i = 0; i < n; i++) {
    dif++;
    while (i + 1 < n && s[i + 1] == s[i]) i++;
  }
  puts(nim[dif]? "Filco" : "Riberto");
  return 0;
}
