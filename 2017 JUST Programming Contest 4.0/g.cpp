#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N];
int mn[N], mx[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    mx[0] = a[0];
    for (int i = 1; i < n; i++) mx[i] = max(mx[i - 1], a[i]);
    mn[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) mn[i] = min(mn[i + 1], a[i]);
    int ans = 0;
    for (int i = 1; i + 1 < n; i++) {
      if (mx[i] <= a[i] && a[i] <= mn[i]) ans++;
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
