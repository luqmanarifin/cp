#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) { 
    int n;
    scanf("%d", &n);
    int am = -inf, an = inf, bm = -inf, bn = inf;
    while(n--) {
      for(int i = 0; i < 4; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        am = max(am, a);
        an = min(an, a);
        bm = max(bm, b);
        bn = min(bn, b);
      }
    }
    printf("%d\n", (am - an) * (bm - bn));
  }
  return 0;
}
