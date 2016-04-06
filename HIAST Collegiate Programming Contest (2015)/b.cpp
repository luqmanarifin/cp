#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int now = 1, rem = n, ans = 0;
    while(rem && now != m) {
      ans++;
      rem -= now;
      rem = max(rem, 0);
      now = min(now * 2, m);
    }
    ans += rem / now + (rem % now? 1 : 0);
    printf("%d\n", ans);
  }
  return 0;
}