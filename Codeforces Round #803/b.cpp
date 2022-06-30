#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
    }
    int ans = 0;
    for (int i = 2; i < n; i++) {
      if (a[i] > a[i-1] + a[i+1]) {
        ans++;
      }
    }
    if (k == 1) {
      ans = (n - 1) / 2;
    }
    printf("%d\n", ans);
  }

  return 0;
}
