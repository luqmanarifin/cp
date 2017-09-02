#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, ada;
    scanf("%d %d", &n, &ada);
    int tot = 0;
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      tot += v;
    }
    int ans = ada / tot + (ada % tot? 1 : 0);
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}