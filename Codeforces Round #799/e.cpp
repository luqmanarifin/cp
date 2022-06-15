#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9;

int a[N], b[N], e[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, s;
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      b[i] = e[i] = inf;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == 1) {
        cnt++;
        b[cnt] = i;
      } 
    }
    cnt = 0;
    for (int i = n; i >= 1; i--) {
      if (a[i] == 1) {
        cnt++;
        e[cnt] = n - i + 1;
      }
    }
    if (s > cnt) {
      printf("-1\n");
      continue;
    }
    int rem = cnt - s, ans = inf;
    for (int lef = 0; lef <= rem; lef++) {
      ans = min(ans, b[lef] + e[rem - lef]);
    }
    printf("%d\n", ans);
  }

  return 0;
}
