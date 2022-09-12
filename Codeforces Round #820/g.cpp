#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 505;

long long dp[N][N][2];
bool can[N][N][2];
bool good[N];
bool fix[N];

char a[N], b[N];

void add(long long& at, long long val) {
  at += val;
  if (at >= MOD) at -= MOD;
}

void trans(int i, int j, int x, int k, int l, int y) {
  add(dp[i][j][x], dp[k][l][y]);
  if (can[k][l][y]) {
    can[i][j][x] = 1;
  }
}

int main() {
  int t;
  scanf("%d", &t);;
  while (t--) {
    memset(dp, 0, sizeof(dp));
    memset(can, 0, sizeof(can));
    memset(good, 0, sizeof(good));
    memset(fix, 0, sizeof(fix));
    scanf("%s %s", a + 1, b + 1);
    int na = strlen(a + 1);
    int nb = strlen(b + 1);
    int D = na / nb;

    for (int i = 1; i + nb - 1 <= na; i++) {
      good[i+nb-1] = 1;
      for (int j = 1; j <= nb; j++) {
        if (a[i+j-1] != b[j]) {
          good[i+nb-1] = 0;
        }
      }
    }
    vector<int> dep;
    for (int len = 1; len < nb; len++) {
      fix[len] = 1;
      for (int i = 0; i < len; i++) {
        if (b[i+1] != b[nb-len+1+i]) {
          fix[len] = 0;
        }
      }
      if (fix[len]) {
        dep.push_back(len);
      }
    }

    dp[0][0][0] = 1;
    can[0][0][0] = 1;
    for (int i = 1; i <= na; i++) {
      for (int j = 0; j <= D; j++) {
        if (good[i]) {
          for (auto it : dep) {
            trans(i, j, 0, i-nb+it, j, 1);
          }
          if (j > 0) {
            trans(i, j, 1, i-nb, j-1, 0);
            trans(i, j, 1, i-nb, j-1, 1);
          }
        } else {
          trans(i, j, 0, i-1, j, 0);
          trans(i, j, 0, i-1, j, 1);
        }
      }
    }
    for (int j = 0; j <= D; j++) {
      if (can[na][j][0] || can[na][j][1]) {
        int ans = (dp[na][j][0] + dp[na][j][1]) % MOD;
        printf("%d %lld\n", j, ans);
        break;
      }
    }
  }

  return 0;
}
