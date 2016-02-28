#include <bits/stdc++.h>

using namespace std;

#define int long long

main() {
  int ans = 0;
  int n, m;
  scanf("%I64d %I64d", &n, &m);
  int bd, bh;
  for(int i = 0; i < m; i++) {
    int d, h;
    scanf("%I64d %I64d", &d, &h);
    if(i == 0) {
      ans = max(ans, h + d - 1);
    }
    if(i) {
      if(abs(bd - d) < abs(bh - h)) {
        puts("IMPOSSIBLE");
        return 0;
      }
      int dif = max(bh, h) - min(bh, h);
      int use = d - bd - dif;
      ans = max(ans, max(bh, h) + use / 2);
    }
    bd = d, bh = h;
  }
  ans = max(ans, bh + n - bd);
  cout << ans << endl;
  return 0;
}
