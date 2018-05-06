
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N], s[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i-1] + a[i];
  }
  int ans = -1e9;
  for (int i = 0; i <= n; i++) {
    int b = s[i];
    int c = s[n] - s[i];
    ans = max(ans, c - b);
  }
  cout << ans << endl;
  return 0;
}
