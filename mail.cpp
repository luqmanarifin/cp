#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 2e9 + 10;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for(int i = 0; i < n; i++) {
    int mn = inf, mx = -inf;
    if(i < n - 1) {
      mn = min(mn, abs(a[i + 1] - a[i]));
      mx = max(mx, abs(a[n - 1] - a[i]));
    }
    if(i > 0) {
      mn = min(mn, abs(a[i] - a[i - 1]));
      mx = max(mx, abs(a[i] - a[0]));
    }
    printf("%d %d\n", mn, mx);
  }
  return 0;
}
