#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = 0;
    for(int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      if(a <= k) ans++;
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
