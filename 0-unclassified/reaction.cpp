// too easy to AC
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

pair<int, int> a[N];
int dp[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i].first, &a[i].second);
  }
  sort(a + 1, a + 1 + n);
  for(int i = 1; i <= n; i++) {
    int id = lower_bound(a + 1, a + 1 + n, make_pair(a[i].first - a[i].second, -1)) - a;
    dp[i] = dp[id - 1] + i - id;
  }
  int ans = 1e9;
  for(int i = 1; i <= n; i++) {
    ans = min(ans, dp[i] + n - i);
  }
  cout << ans << endl;
  return 0;
}
