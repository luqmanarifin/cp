#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int inf = 1e9;

int d[N][N];
char s[N], buf[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        d[i][j] = inf;
      }
      d[i][i] = 0;
    }

    scanf("%s", s);
    int n = strlen(s);
    int v;
    scanf("%d", &v);
    while (v--) {
      scanf("%s", buf);
      d[buf[0] - 'A'][buf[1] - 'A'] = 1;
    }
    for (int k = 0; k < 26; k++) {
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
    int ans = inf;
    for (int goal = 0; goal < 26; goal++) {
      int cur = 0;
      for (int i = 0; i < n; i++) {
        cur += d[s[i] - 'A'][goal];
        if (cur >= inf) break;
      }
      ans = min(ans, cur);
    }
    if (ans >= inf) ans = -1;
    printf("Case #%d: %d\n", tt, ans);
  }

  return 0;
}
