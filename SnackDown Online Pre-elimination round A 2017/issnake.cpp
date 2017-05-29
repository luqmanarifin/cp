#include <bits/stdc++.h>

using namespace std;

const int N = 505;

char s[2][N];
bool valid[2][N];
int n;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(valid, 0, sizeof(valid));
    scanf("%d %s %s", &n, s[0], s[1]);
    bool udah = 0;
    for (int i = 0; i < n; i++) {
      if (!udah) {
        if (s[0][i] == '#' && s[1][i] == '#') {
          valid[0][i] = valid[1][i] = 1;
        } else if (s[0][i] == '#') {
          valid[0][i] = 1;
        } else if (s[1][i] == '#') {
          valid[1][i] = 1;
        }
      } else {
        if (s[0][i] == '#' && s[1][i] == '#') {
          if (valid[0][i-1]) valid[1][i] = 1;
          if (valid[1][i-1]) valid[0][i] = 1;
        } else if (s[0][i] == '#') {
          if (valid[0][i-1]) valid[0][i] = 1;
        } else if (s[1][i] == '#') {
          if (valid[1][i-1]) valid[1][i] = 1;
        }
      }
      if (s[0][i] == '#' || s[1][i] == '#') {
        udah = 1;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      bool nice = (s[0][i] == '#' || s[1][i] == '#');
      if (nice) {
        puts(valid[0][i] || valid[1][i]? "yes" : "no");
        break;
      }
    }
  }

  return 0;
}
