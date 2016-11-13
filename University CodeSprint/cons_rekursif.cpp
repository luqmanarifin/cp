#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 55;

int dp[55][205][2005];
int n, S, K;

int dfs(int now, int s, int k, int v) {
  if (dp[now][s][k] != inf) return 0;
  //printf("%d %d %d\n", now, s, k);
  dp[now][s][k] = v;
  if (now == n && s == S) {
    if (k == K) return 1;
    return 0;
  }
  int tn, ts, tk, add;
  add = 0;
  tn = now + 1;
  ts = s;
  tk = k;
  if (tn <= n && ts <= S && tk <= K) {
    if (dfs(tn, ts, tk, add)) return 1;
  }
  add++;
  tn = now;
  ts = s + n + 1 - now;
  tk = k + (now - 1)*(n - now + 1);
  if (tn <= n && ts <= S && tk <= K) {
    if (dfs(tn, ts, tk, add)) return 1;
  }
  return 0;
}

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 205; j++) {
      fill(dp[i][j], dp[i][j] + 2005, inf);
    }
  }
  
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &S, &K);
    dfs(1, 0, 0, 0);
    
    if (dp[n][S][K] == inf) {
      puts("-1");
    } else {
      vector<int> ans;
      ans.assign(n, 0);
      int i = n;
      while (S || K) {
        int add = dp[i][S][K];
        //printf("%d %d %d %d\n", i, S, K, add);
        ans[i - 1] += add;
        if (add == 0) {
          i--;
        } else {
          S -= n + 1 - i;
          K -= (i - 1)*(n - i + 1);
        }
      }
      assert(S == 0 && K == 0);
      for (i = 1; i < ans.size(); i++) ans[i] += ans[i - 1];
      for (auto it : ans) printf("%d ", it); printf("\n");
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 205; j++) {
        fill(dp[i][j], dp[i][j] + 2005, inf);
      }
    }
  }

  return 0;
}
