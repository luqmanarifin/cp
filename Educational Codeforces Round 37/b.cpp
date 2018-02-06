#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int now = 0;
    for (int i = 0; i < n; i++) {
      int l, r;
      scanf("%d %d", &l, &r);
      int got = max(now + 1, l);
      if (got <= r) {
        now = got;
        printf("%d ", now);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
  
  return 0;
}
