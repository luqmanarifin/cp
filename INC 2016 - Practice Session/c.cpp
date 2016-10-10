#include <bits/stdc++.h>

using namespace std;

const int N = 25;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    int pat = 0, lim = 0, nam = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      int len = strlen(s);
      if (len == 4) {
        pat++;
      } else if (len == 5) {
        lim++;
      } else if (len == 6) {
        nam++;
      }
    }
    printf("Case #%d: %d %d %d\n", tt, pat, lim, nam);
  }

  return 0;
}
