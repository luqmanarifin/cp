#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    int now = 0;
    for (int i = 0; i < n; i++) {
      if (now + 1 <= a[i]) {
        now++;
      }
    }
    printf("Case #%d: %d\n", tt, now);
  }

  return 0;
}
