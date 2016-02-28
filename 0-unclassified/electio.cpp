#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int a[105], b[105];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int ans = inf;
  for(int lim = 0; lim <= 1000; lim++) {
    for(int i = 0; i < n; i++) {
      b[i] = a[i];
    }
    int cur = 0, free = 0;
    for(int i = 1; i < n; i++) {
      if(b[i] > lim) {
        cur += b[i] - lim;
        b[0] += b[i] - lim;
        b[i] = lim;
      }
      free += b[i];
    }
    if(b[0] <= lim) {
      cur += lim + 1 - b[0];
      b[0] += min(free, lim + 1 - b[0]);
    }
    if(b[0] > lim) {
      ans = min(ans, cur);
    }
  }
  cout << ans << endl;
  return 0;
}
