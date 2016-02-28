#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int ans = n * (m / k) + (m % k? 1 : 0) + k - 1;
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
