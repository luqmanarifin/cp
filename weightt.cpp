#include <bits/stdc++.h>

using namespace std;

int a[55];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    for(int i = 0; i < 5; i++) {
      scanf("%d", a + i);
    }
    int x;
    scanf("%d", &x);
    printf("Case #%d: ", tt);
    bool found = 0;
    for(int mask = 0; mask < (1 << 5); mask++) {
      int sum = 0;
      for(int i = 0; i < 5; i++) {
        if(mask & (1 << i)) {
          sum += a[i];
        }
      }
      if(sum == x) {
        puts("YES");
        found = 1;
        break;
      }
    }
    if(!found) puts("NO");
  }
  
  return 0;
}
