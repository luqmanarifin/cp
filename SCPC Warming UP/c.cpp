#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];

int main(){
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) scanf("%d", b + i);
    sort(a, a + n);
    reverse(a, a + n);
    bool win = 1;
    int now = 0;
    for (int i = 0; i < n; i++) {
      now += a[i];
      if (now >= b[i]) {
        now -= b[i];
      } else {
        win = 0;
        break;
      }
    }
    printf("Case #%d: ", tt);
    if (win) {
      puts("Yes he made it");
    } else {
      puts("IMPOSSIBLE");
    }
  }
  
  
  return 0;
};