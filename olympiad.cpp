#include <bits/stdc++.h>

using namespace std;

int a[20];

int main() {
  int n, l, r, x;
  scanf("%d %d %d %d", &n, &l, &r, &x);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int ans = 0;
  for(int mask = 0; mask < (1 << n); mask++) {
    int bit = __builtin_popcount(mask);
    if(mask < 2) continue;
    int mini = 1e9, maxi = -1e9, sum = 0;
    for(int i = 0; i < n; i++) if(mask & (1 << i)) {
      mini = min(mini, a[i]);
      maxi = max(maxi, a[i]);
      sum += a[i];
    }
    if(l <= sum && sum <= r && abs(mini - maxi) >= x) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
