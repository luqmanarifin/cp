#include <bits/stdc++.h>

using namespace std;

const int N = 1105;
const int inf = 1e9;

int dp[2][N][55][55];
int got[2][N], good[2][N], sum[2][N];

void upd(int& at, int val) {
  at = max(at, val);
}

int main() {
  int n, p, K;
  scanf("%d %d %d", &n, &p, &K);
  for (int t = 0; t < 2; t++) {
    int r;
    scanf("%d", &r);
    //if (K == 33 && t == 1) printf("%d ", r);
    while (r--) {
      int v;
      scanf("%d", &v);
      //if (K == 33 && t == 1) printf("%d ", v);
      good[t][v] = 1;
    }
    for (int i = 1; i < N; i++) sum[t][i] = sum[t][i-1] + good[t][i];
    for (int i = 1; i <= n; i++) {
      got[t][i] = sum[t][i+K-1] - sum[t][i-1];
    } 
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 55; j++) {
      for (int k = 0; k < 55; k++) {
        dp[0][i][j][k] = dp[1][i][j][k] = -inf;
      }
    }
  }
  p = min(p, 2 * ((n + K - 1) / K));
  dp[0][0][0][0] = 0;
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= p; j++) {
      for (int a = 0; a <= K; a++) {
        for (int b = 0; b <= K; b++) {
          int s = (i % 2), t = (s ^ 1);
          int add = ((good[0][i+1] && a) || (good[1][i+1] && b));
          upd(dp[t][j][max(0,a-good[0][i+1])][max(0,b-good[1][i+1])], dp[s][j][a][b] + add);
          if (a == 0) upd(dp[s][j+1][got[0][i+1]][b], dp[s][j][a][b]);
          if (b == 0) upd(dp[s][j+1][a][got[1][i+1]], dp[s][j][a][b]);
          if (i == n) ans = max(ans, dp[s][j][a][b]);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
