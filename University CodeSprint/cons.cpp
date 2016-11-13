#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int inf = 1e9;

int lims[N], limk[N];
int dp[N][205][2005];

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 205; j++) {
      fill(dp[i][j], dp[i][j] + 2005, inf);
    }
  }
  
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, S, K;
    scanf("%d %d %d", &n, &S, &K);
    int iter = 0;
    for (int i = 1; i <= n; i++) {
      lims[i] = S;
      limk[i] = K;
      //lims[i] = S / n + (n - i < S % n) + lims[i - 1];
      //limk[i] = min(K, lims[i] * (i - 1));
      //printf("%d %d\n", lims[i], limk[i]);
      iter += lims[i] * limk[i];
    }
    //cout << iter << endl;
    dp[1][0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= lims[i]; j++) {
        for (int k = 0; k <= limk[i]; k++) {
          if (dp[i][j][k] == inf) continue;
          //printf("%d %d %d: %d\n", i, j, k, dp[i][j][k]);
          int add = dp[i][j][k];
          int ti = i + 1;
          int tj = j;
          int tk = k;
          if (ti <= n && tj <= lims[ti] && tk <= limk[ti] && dp[ti][tj][tk] == inf) {
            dp[ti][tj][tk] = 0;
            if (ti == n && tj == S && tk == K) goto SIP;
          }
          ti = i;
          tj = j + n + 1 - i;
          tk = k + (i - 1)*(n - i + 1);
          if (tj <= lims[i] && tk <= limk[i] && dp[ti][tj][tk] == inf) {
            dp[ti][tj][tk] = 1;
            if (ti == n && tj == S && tk == K) goto SIP;
          }
        }
      }
    }
    SIP:;
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
