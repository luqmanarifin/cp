#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int need[N], a[N];

int main() {
  for (int i = 1; i < N; i++) {
    need[i] = 1;
    while (need[i] * i < 50) need[i]++;
  }
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    int b = 0, e = n - 1;
    int ans = 0;
    while (b <= e) {
      //printf("%d %d\n", b, e);
      int rem = need[a[e]] - 1;
      if (b + rem <= e) {
        //puts("yes");
        ans++;
        e--;
        b += rem;
      } else {
        break;
      }
    }    
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}
