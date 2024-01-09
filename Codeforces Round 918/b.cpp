#include <bits/stdc++.h>

using namespace std;

const int N = 5;

char s[N][N];
char cnt[256];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n = 3;
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < n; i++) {
      memset(cnt, 0, sizeof(cnt));
      bool has = 0;
      for (int j = 0; j < n; j++) {
        if (s[i][j] == '?') has = 1;
        cnt[s[i][j]]++;
      }
      if (has) {
        for (char c = 'A'; c <= 'C'; c++) {
          if (cnt[c] == 0) printf("%c\n", c);
        }
      }
    }
  }

  return 0;
}
