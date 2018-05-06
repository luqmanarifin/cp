
#include <bits/stdc++.h>

using namespace std;

const int N = 35;

char s[N];
int pre[N];

int main() {
  int tc;
  scanf("%d", &tc);
  for (int tt = 1; tt <= tc; tt++) {
    int d;
    scanf("%d %s", &d, s);
    int n = strlen(s);
    int now = 0; long long damage = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'C') {
        now++;
      } else {
        damage += (1 << now);
        pre[i] = now;
      }
    }
    int ans = 0;
    while (damage > d) {
      bool ada = 0;
      for (int i = n - 1; i >= 1; i--) {
        if (s[i - 1] == 'C' && s[i] == 'S') {
          ada = 1;
          ans++;
          damage -= (1 << pre[i]);
          pre[i]--;
          damage += (1 << pre[i]);
          swap(pre[i], pre[i-1]);
          swap(s[i], s[i-1]);
          break;
        }
      }
      if (!ada) break;
    }
    printf("Case #%d: ", tt);
    if (d < damage) {
      puts("IMPOSSIBLE");
    } else {
      printf("%d\n", ans);
    }
  }

  return 0;
}
