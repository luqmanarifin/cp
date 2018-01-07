#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long inf = 1e18;

int a[N];
long long dp[N];
bool bad[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  bad[1] = bad[n] = 1;
  for (int i = 2; i < n; i++) {
    if (a[i-1] < a[i] && a[i] < a[i+1]) continue;
    if (a[i-1] > a[i] && a[i] > a[i+1]) continue;
    bad[i] = bad[i-1] = 1;
  }
  fill(dp, dp + N, inf);
  dp[0] = 0;
  vector<int> num = {0};
  for (int i = 1; i <= n; i++) {
    for (int j = max(0, (int) num.size() - 3); j < num.size(); j++) {
      dp[i] = min(dp[i], dp[j] + abs(a[i] - a[num[j] + 1]));
    }
    if (bad[i]) num.push_back(i);
  }
  cout << dp[n] << endl;
  return 0;
}
