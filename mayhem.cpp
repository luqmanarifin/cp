#include <bits/stdc++.h>

using namespace std;

const int N = 9;
const int mod = 1e9 + 7;

// mask sebelumnya (1 kehalang) - block sekarang
int be[1 << N][1 << N];
int dp[N][1 << N][N * N];
vector<int> ways[N];
int n, m;
int comb[N * N][N * N];

void generate(int mask, int b) {
  int ret = (1 << m) - 1;
  for(int i = 0; i < m; i++) {
    if((mask & (1 << i)) == 0 && ((b & (1 << i)) == 0)) {
      ret &= ~(1 << i);
    }
  }
  for(int i = 0; i < m - 1; i++) {
    if((ret & (1 << i)) == 0 && ((b & (1 << (i + 1))) == 0)) {
      ret &= ~(1 << (i + 1));
    }
  }
  be[mask][b] = ret;
}

int find(int now, int mask, int c) {
  int& ret = dp[now][mask][c];
  if(ret != -1) return ret;
  if(now == n - 1) {
    if((mask & (1<<(m-1))) == 0) {
      return ret = 1;
    }
    return ret = 0;
  }
  ret = 0;
  for(int i = 0; i <= min(c, m); i++) {
    for(int block : ways[i]) {
      ret += find(now + 1, be[mask][block], c - i);
      if(ret >= mod) ret -= mod;
    }
  }
  return ret;
}

int main() {
  for(int i = 0; i < N * N; i++) {
    for(int j = 0; j <= i && j < N * N; j++) {
      if(i == j || j == 0) {
        comb[i][j] = 1;
      } else {
        comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
      }
    }
  }
  
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < (1 << m); i++) {
      for(int j = 0; j < (1 << m); j++) {
        generate(i, j);
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < (1 << m); j++) {
        for(int k = 0; k <= n * m; k++) {
          dp[i][j][k] = -1;
        }
      }
    }
    for(int i = 0; i <= m; i++) ways[i].clear();
    for(int i = 0; i < (1 << m); i++) {
      ways[__builtin_popcount(i)].push_back(i);
    }
    int ans = 0;
    for(int i = 0; i <= min(k, m); i++) {
      for(int block : ways[i]) {
        if(block & 1) continue;
        int mask = block;
        for(int i = 1; i < m; i++) {
          if(mask & (1<<(i-1))) {
            mask |= (1 << i);
          }
        }
        ans += find(0, mask, k - i);
        if(ans >= mod) ans -= mod;
      }
    }
    int all = 0;
    for(int i = 0; i <= k; i++) {
      all += comb[n * m][i];
      if(all >= mod) all -= mod;
    }
    ans = all - ans;
    if(ans < 0) ans += mod;
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
