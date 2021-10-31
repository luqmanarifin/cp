#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      if (a[i] > i) {
        ans = max(ans, a[i] - i);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
