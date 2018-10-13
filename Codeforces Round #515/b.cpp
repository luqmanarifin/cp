#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int a[N];

int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int now = -1, ans = 0;
  while (now < n - 1) {
    bool ada = 0; int at = -1;
    // printf("now %d: %d %d\n", now, now + 2 - r, now + r);
    for (int i = now + r; i >= now + 2 - r && i >= 0; i--) {
      if (a[i]) {
        ada = 1;
        at = i;
        break;
      }
    }
    // printf("at %d\n", at);
    if (!ada) {
      puts("-1");
      return 0;
    }
    ans++;
    now = at + r - 1;
  }
  cout << ans << endl;
  return 0;
}
