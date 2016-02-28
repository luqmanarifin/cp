#include <bits/stdc++.h>

using namespace std;

#define int long long

bool done[1005];
int x[1005], y[1005];

main() {
  int ans = 0;
  int n, x0, y0; 
  scanf("%I64d %I64d %I64d", &n, &x0, &y0);
  for(int i = 0; i < n; i++) {
    scanf("%I64d %I64d", x + i, y + i);
  }
  for(int i = 0; i < n; i++) {
    if(done[i]) continue;
    done[i] = 1;
    ans++;
    int xi = x0 - x[i];
    int yi = y0 - y[i];
    for(int j = 0; j < n; j++) {
      int xj = x0 - x[j];
      int yj = y0 - y[j];
      if(xj * yi == xi * yj) {
        done[j] = 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}