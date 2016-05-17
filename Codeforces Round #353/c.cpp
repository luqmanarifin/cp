#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;
const int inf = 1e9;

long long a[N], s[N];
int to[N];

int dp[N], mark[N];
int cnt;

void dfs(int p, int goal) {
  if(p > inf) return;
  if(p == goal) {
    mark[p] = cnt;
    dp[p] = N;
    return;
  }
  if(dp[p] != -1) return;
  dfs(to[p] + 1, goal);
  if(to[p] < inf) {
    mark[p] = mark[to[p] + 1];
    dp[p] = dp[to[p] + 1] - 1;
  } else {
    mark[p] = cnt;
    dp[p] = N;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
    a[i + n] = a[i];
  }
  for(int i = 1; i <= 2 * n; i++) {
    s[i] = s[i - 1] + a[i];
  }
  map<long long, int> last;
  for(int i = 2*n; i >= 1; i--) {
    last[s[i]] = i;
    if(last.count(s[i - 1])) {
      to[i] = last[s[i - 1]];
    } else {
      to[i] = inf + 5;
    }
    to[i + n] = to[i] + n;
  }
  memset(dp, -1, sizeof(dp));
  
  int ans = n;
  for(int i = n; i >= 1; i--) {
    cnt++;
    dfs(i, i + n);
    if(mark[i] == mark[i + n]) {
      ans = min(ans, n - dp[i + n] + dp[i]);
    }
  }
  cout << ans << endl;
  return 0;
}