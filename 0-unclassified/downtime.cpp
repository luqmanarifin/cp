#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n, k;
  int ans = 0;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for(int i = 0; i < n; i++) {
    int cur = upper_bound(a, a + n, a[i]) - lower_bound(a, a + n, a[i]-999);
    int cnt = cur / k + (cur % k? 1 : 0);
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
