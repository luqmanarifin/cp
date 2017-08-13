#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  set<char> c;
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; j++) {
      c.insert(s[i][j]);
    }
  }
  if (c.size() != 3) {
    puts("NO");
    return 0;
  }
  if (n % 3 == 0) {
    bool good = 1;
    for (int k = 0; k < n; k += n / 3) {
      bool same = 1;
      char root = s[k][0];
      for (int i = 0; i < n / 3; i++) {
        for (int j = 0; j < m; j++) {
          if (s[k + i][j] != root) {
            same = 0;
          }
        }
      }
      if (!same) {
        good = 0;
        break;
      }
    }
    if (good) {
      puts("YES");
      return 0;
    }
  }
  if (m % 3 == 0) {
    bool good = 1;
    for (int k = 0; k < m; k += m / 3) {
      bool same = 1;
      char root = s[0][k];
      for (int j = 0; j < m / 3; j++) {
        for (int i = 0; i < n; i++) {
          if (s[i][j + k] != root) {
            same = 0;
          }
        }
      }
      if (!same) {
        good = 0;
        break;
      }
    }
    if (good) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
