#include <bits/stdc++.h>

using namespace std;

int ep[101][101][101][101];
int dp[101][101][101];
int fp[101][101];

int cok(int a, int b) {
  if (a + b == 0) return -1;
  if (fp[a][b] != -1) return fp[a][b];
  int& ret = fp[a][b] = 0;
  if (a >= 1) ret = max(ret, cok(a - 1, b) + 1);
  if (b >= 2) ret = max(ret, cok(a, b - 2) + 1);
  return ret;
}

int solve(int a, int b, int c) {
  if (a + b + c == 0) return -1;
  if (dp[a][b][c] != -1) return dp[a][b][c];
  int& ret = dp[a][b][c] = 0;
  if (a >= 1) ret = max(ret, solve(a - 1, b, c) + 1);
  if (b >= 3) ret = max(ret, solve(a, b - 3, c) + 1);
  if (c >= 3) ret = max(ret, solve(a, b, c - 3) + 1);
  if (b >= 1 && c >= 1) ret = max(ret, solve(a, b - 1, c - 1) + 1);
  //printf("%d %d %d: %d\n", a, b, c, ret);
  return ret;
}

int sol(int a, int b, int c, int d) {
  if (a + b + c + d == 0) return -1;
  if (ep[a][b][c][d] != -1) return ep[a][b][c][d];
  int& ret = ep[a][b][c][d] = 0;
  if (a >= 1) ret = max(ret, sol(a - 1, b, c, d) + 1);
  if (b >= 4) ret = max(ret, sol(a, b - 4, c, d) + 1);
  if (c >= 2) ret = max(ret, sol(a, b, c - 2, d) + 1);
  if (d >= 4) ret = max(ret, sol(a, b, c, d - 4) + 1);
  if (b >= 2 && c >= 1) ret = max(ret, sol(a, b - 2, c - 1, d) + 1);
  if (b >= 1 && d >= 1) ret = max(ret, sol(a, b - 1, c, d - 1) + 1);
  if (c >= 1 && d >= 2) ret = max(ret, sol(a, b, c - 1, d - 2) + 1);
  return ret;
}

int cnt[5];

int main() {
  memset(fp, -1, sizeof(fp));
  memset(ep, -1, sizeof(ep));
  memset(dp, -1, sizeof(dp));
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(cnt, 0, sizeof(cnt));
    
    int n, p;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      cnt[v % p]++;
    }
    int ans;
    if (p == 2) {
      ans = cok(cnt[0], cnt[1]) + 1;
    } else if (p == 3) {
      ans = solve(cnt[0], cnt[1], cnt[2]) + 1;
    } else {
      ans = sol(cnt[0], cnt[1], cnt[2], cnt[3]) + 1;
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}
