#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    int ans = a[n - 1] - a[0];
    for (int i = 0; i < n; i++) {
      ans = max(ans, a[i] - a[(i+1)%n]);
    }
    int mn = a[0];
    for (int i = 0; i + 1 < n; i++) mn = min(mn, a[i]);
    int mx = a[n-1];
    for (int i = 1; i < n; i++) mx = max(mx, a[i]);
    ans = max(ans, a[n-1] - mn);
    ans = max(ans, mx - a[0]);
    printf("%d\n", ans);
  } 

  return 0;
}
