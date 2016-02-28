#include <bits/stdc++.h>

using namespace std;

int a[105];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, m;
    scanf("%d %d", &n, &m);
    int ans = 0;
    for(int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      ans += v <= m;
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
