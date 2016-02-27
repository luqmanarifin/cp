#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  int ans = 2e9;
  for(int i = 0; i + k <= n; i++) {
    ans = min(ans, a[i + k - 1] - a[i]);
  }
  cout << ans << endl;
  return 0;
}
