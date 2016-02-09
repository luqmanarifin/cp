#include <bits/stdc++.h>

/**
 * Hayo mau liat apa
 * Asu kon
 */

using namespace std;

char s[1005];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n;
    memset(s, 0, sizeof(s));
    scanf("%d %s", &n, s);
    for(int i = 0; i < n + 1; i++) {
      s[i] -= '0';
    }
    int now = 0, ans = 0;
    for(int i = 0; i < n + 1; i++) {
      if(now < i && s[i]) {
        ans += i - now;
        now = i;
      }
      now += s[i];
    }
    printf("Case #%d: %d\n", tt, ans);
    cerr << tt << " udah! Answer = " << ans << endl;
  }
  
  return 0;
}
