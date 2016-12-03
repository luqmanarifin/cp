#include <bits/stdc++.h>

using namespace std;

#define MAXP 100
#define MAXN 8

int dp[MAXP+5][(1<<MAXN)+5], ndp[MAXP+5][(1<<MAXN)+5];
int E[MAXN+5], P[MAXN+5];

int main()
{
  int ntc;
  scanf("%d", &ntc);
  while (ntc--) {
    int K,M;
    memset(dp, 0, sizeof(dp));
    scanf("%d%d", &K, &M);
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", &E[i]);
    for (int i = 0; i < N; ++i) scanf("%d", &P[i]);
    dp[0][0] = 100;
    int ans = 0;
    while (true) {
      for (int m = 0; m <= (1<<N); ++m) {
        for (int p = 0; p < 100; ++p) {
          if (dp[p][m] <= K) continue;
          int &s = ndp[max(p-M,0)][m];
          s = max(s, min(dp[p][m]-K,100));
          //printf("%d\n", s);
          for (int i = 0; i < N; ++i) {
            if (m != (m | (1<<i)) && max(p-M,0)+P[i] < 100) {
              int &r = ndp[max(p-M,0)+P[i]][m|(1<<i)];
              r = max(r, min(dp[p][m]-K+E[i],100));
              //printf("%d %d %d %d\n", p, m, i, r);
            }
          }
        }
      }
      bool ok = false;
      for (int m = 0; m <= (1<<N); ++m) {
        for (int p = 0; p < 100; ++p) {
          dp[p][m] = ndp[p][m];
          ndp[p][m] = 0;
          if (dp[p][m] > 0) ok = true;
        }
      }
      if (!ok) break;
      ++ans;
    }
    printf("%d\n", ans);
  }
  return 0;
}