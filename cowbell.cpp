#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int alone = min(n, 2 * k - n);
  int duo = n - alone;
  int ans = 0;
  for(int i = 0; i < alone; i++) {
    ans = max(ans, a[n - 1 - i]);
  }
  for(int i = 0; i < duo; i++) {
    ans = max(ans, a[i] + a[duo - 1 - i]);
  }
  cout << ans << endl;
  return 0;
}
