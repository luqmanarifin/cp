#include <bits/stdc++.h>

using namespace std;

int a[105];
bool ok[10005];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    for(int i = 0; i <= m; i++) ok[i] = 0;
    ok[0] = 1;
    printf("Case #%d: ", tt);
    if(a[0] > m) {
      puts("HAPPY BIRTHDAY ANTONIO");
      continue;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(a[i] <= m) {
        ans = a[i];
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
