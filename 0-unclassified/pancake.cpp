#include <bits/stdc++.h>

/**
 * Hayo mau liat apa
 * Asu kon
 */

using namespace std;

const int inf = 1e9;

int p[1005];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n;
    memset(p, 0, sizeof(p));
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", p + i);
    }
    int ans = inf;
    for(int f = 1000; f >= 1; f--) {
      int cur = f;
      for(int i = 0; i < n; i++) {
        if(f < p[i]) {
          cur += (p[i] - f) / f + ((p[i] - f) % f ? 1 : 0);
        }
      }
      ans = min(ans, cur);
    }
    printf("Case #%d: %d\n", tt, ans);
    cerr << tt << " udah. ans = " << ans << endl;
  }
  
  return 0;
}
