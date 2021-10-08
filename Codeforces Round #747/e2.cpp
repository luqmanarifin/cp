#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int C = 6;

int c[6][6] = {
  {0, 0, 1, 1, 1, 1},
  {0, 0, 1, 1, 1, 1},
  {1, 1, 0, 0, 1, 1},
  {1, 1, 0, 0, 1, 1},
  {1, 1, 1, 1, 0, 0},
  {1, 1, 1, 1, 0, 0}
};

string S = "wygbro";

long long pre[100][C];
map<long long, vector<long long>> dp;
int n;

map<long long, bool> vis;
map<long long, int> col;
char s[25];

void fill(long long now, int lvl) {
  int p = n - lvl + 1;
  vector<long long> v(C);
  for (int i = 0; i < C; i++) v[i] = pre[p][i];
  dp[now] = v;
}

void dfs(long long now, int lvl) {
  long long lef = 2 * now;
  long long rig = 2 * now + 1;
  if (vis.count(lef)) {
    dfs(lef, lvl + 1);
  } else {
    fill(lef, lvl + 1);
  }
  if (vis.count(rig)) {
    dfs(rig, lvl + 1);
  } else {
    fill(rig, lvl + 1);
  }
  dp[now] = vector<long long>(C, 0);
  if (lvl == n) {
    dp[now] = vector<long long>(C, 1);
  } else {
    for (int i = 0; i < C; i++) {
      for (int j = 0; j < C; j++) {
        if (c[i][j] == 0) continue;
        for (int k = 0; k < C; k++) {
          if (c[i][k] == 0) continue;
          dp[now][i] += dp[lef][j] * dp[rig][k] % mod;
          dp[now][i] %= mod;
        }
      }
    }
  }
  if (col.count(now)) {
    for (int i = 0; i < C; i++) {
      if (i != col[now]) {
        dp[now][i] = 0;
      }
    }
  }
}

int main() {
  for (int i = 0; i < C; i++) pre[1][i] = 1;
  for (int i = 2; i <= 60; i++) {
    for (int j = 0; j < C; j++) {
      for (int k = 0; k < C; k++) {
        if (c[j][k] == 0) continue;
        for (int l = 0; l < C; l++) {
          if (c[j][l] == 0) continue;
          pre[i][j] += pre[i-1][k] * pre[i-1][l] % mod;
          pre[i][j] %= mod;
        }
      }
    }
  }
  int k;
  scanf("%d %d", &n, &k);
  while (k--) {
    long long v;
    scanf("%lld %s", &v, s);
    int tmp = -1;
    for (int i = 0; i < C; i++) {
      if (s[0] == S[i]) tmp = i;
    }
    col[v] = tmp;
    while (v > 0) {
      vis[v] = 1;
      v /= 2;
    }
  }
  dfs(1, 1);
  long long ans = 0;
  for (int i = 0; i < C; i++) ans += dp[1][i];
  cout << ans % mod << endl;
  return 0;
}
