#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    int now = n - k;
    int ans = 1 + now / (k - 1) + (now % (k - 1)? 1 : 0);
    printf("%d\n", ans);
  }

  return 0;
}
