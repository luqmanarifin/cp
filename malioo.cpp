#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main() {
  int n;
  scanf("%d", &n);
  int ans = inf;
  for(int i = 0; i < n; i++) {
    int h, t;
    scanf("%d %d", &h, &t);
    ans = min(ans, h * (100 - t) / 100);
  }
  if(ans % 100 > 0) {
    ans = ans / 100 * 100;
  }
  printf("%d\n", ans);
  return 0;
}
