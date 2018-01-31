#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const long long inf = 1e18 + 7;

int r[N], s[N];
int n;
long long dp[N][N][2];
long long sum[N];
int vis[N][N][2];

long long solve(int k, int score, int turn) {
  if (k == n) return score? inf : -inf;
  if (turn == 0) {
    if (vis[k][score][turn]) return dp[k][score][turn];
    vis[k][score][turn] = 1;
    
    long long & ret = dp[k][score][turn] = inf;
    // pass
    long long nxt = solve(k+1, score, turn);
    ret = min(ret, max(nxt+1+r[k], 1LL));
    // pick
    nxt = solve(k+1, max(0, score - s[k]), turn ^ 1);
    ret = min(ret, nxt - r[k]);
    //cerr << k << " " << score << " " << turn << ": " << ret << endl;
    return ret;
    
  } else {
    if (vis[k][score][turn]) return dp[k][score][turn];
    vis[k][score][turn] = 1;
    long long & ret = dp[k][score][turn] = -inf;
    // pass
    long long nxt = solve(k+1, max(0, score - s[k]), turn);
    ret = max(ret, min(nxt-1-r[k], -1LL));
    // pick
    nxt = solve(k+1, score, turn ^ 1);
    ret = max(ret, nxt + r[k]);
    //cerr << k << " " << score << " " << turn << ": " << ret << endl;
    return ret;
  }
}

int main() {
  int a, b;
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", r+i, s+i);
  }
  sum[n] = 0;
  for (int i = n-1; i >= 0; --i)
    sum[i] = sum[i+1] + s[i];
  
  int ans = 0;
  for (int i = sum[0]; i >= 0; --i) {
    if (solve(0, i, 0) <= a-b) {
      ans = i;
      break;
    }
  }
  printf("%d %d\n", ans, sum[0] - ans);
  return 0;
}