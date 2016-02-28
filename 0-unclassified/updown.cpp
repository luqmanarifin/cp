#include <bits/stdc++.h>

using namespace std;

int a[1005];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    int l = 0, r = n - 1;
    int ans = 0;
    while(n--) {
      int pt = l;
      for(int i = l + 1; i <= r; i++) {
        if(a[i] < a[pt]) {
          pt = i;
        }
      }
      if(r - pt < pt - l) {
        ans += r - pt;
        for(int i = pt + 1; i <= r; i++) {
          swap(a[i], a[i - 1]);
        }
        r--;
      } else {
        ans += pt - l;
        for(int i = pt - 1; i >= l; i--) {
          swap(a[i], a[i + 1]);
        }
        l++;
      }
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
