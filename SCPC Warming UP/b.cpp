#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int l = a / c * c;
    if (l < a) {
      l += c;
    }
    int r = b / c * c;
    int ans = 0;
    if (l <= r) ans = (r - l) / c + 1;
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
};