#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

long long dp[65][1 << 10][3];

int a[N];
int b[N];
int c[N];
int pt;

int base;
int len;
int sample[N];

long long dfs(int now, int mask, int t) {
  if (dp[now][mask][t] != -1) return dp[now][mask][t];
  if (t == 2 && now >= len) return 0;
  if (now == len) {
    //printf("done %d %d %d: %d\n", now, mask, t, !mask);
    return !mask;
  }
  long long& ret = dp[now][mask][t] = !mask;
  if (t == 0) {
    for (int i = 0; i < base; i++) {
      ret += dfs(now + 1, mask ^ (1 << i), 0);
    }
  } else if (t == 1) {
    for (int i = 0; i < sample[now]; i++) {
      ret += dfs(now + 1, mask ^ (1 << i), 0);
    }
    ret += dfs(now + 1, mask ^ (1 << sample[now]), 1);
    for (int i = sample[now] + 1; i < base; i++) {
      ret += dfs(now + 1, mask ^ (1 << i), 2);
    }
  } else {
    for (int i = 0; i < base; i++) {
      ret += dfs(now + 1, mask ^ (1 << i), 2);
    }
  }
  a[pt] = now;
  b[pt] = mask;
  c[pt] = t;
  pt++;
  //printf("%d %d %d: %lld\n", now, mask, t, ret);
  return ret;
}

long long solve(long long lim) {
  if (lim == 0) return 0;

  len = 0;
  while (lim > 0) {
    sample[len] = lim % base;
    lim /= base;
    len++;
  }
  reverse(sample, sample + len);

  for (int now = len; now >= 0; now--) {
    for (int t = 0; t < 3; t++) {
      if (now == len && t == 2) continue;
      dp[now][0][t] = 1;
    }
    for (int mask = 0; mask < (1 << base); mask++) {
      for (int i = 0; i < base; i++) {
        dp[now][mask][0] += dp[now + 1][mask ^ (1 << i)][0];
      }

      for (int i = 0; i < sample[now]; i++) {
        dp[now][mask][1] += dp[now + 1][mask ^ (1 << i)][0];
      }
      dp[now][mask][1] += dp[now + 1][mask ^ (1 << sample[now])][1];
      for (int i = sample[now] + 1; i < base; i++) {
        dp[now][mask][1] += dp[now + 1][mask ^ (1 << i)][2];
      }

      for (int i = 0; i < base; i++) {
        dp[now][mask][2] += dp[now + 1][mask ^ (1 << i)][2];
      }
    }

  }

  long long ret = 0;
  for (int i = 1; i < sample[0]; i++) {
    ret += dp[1][1 << i][0];
  }
  ret += dp[1][1 << sample[0]][1];
  for (int i = sample[0] + 1; i < base; i++) {
    ret += dp[1][1 << i][2];
  }

  for (int i = 0; i <= len; i++) {
    for (int j = 0; j < (1 << base); j++) {
      for (int k = 0; k < 3; k++) {
        dp[i][j][k] = 0;
      }
    }
  }
  
  return ret;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long l, r;
    scanf("%d %lld %lld", &base, &l, &r);
    long long rig = solve(r);
    long long lef = solve(l - 1);
    //printf("lef rig %lld %lld\n", lef, rig);
    printf("%lld\n", rig - lef);
  }
  return 0;
}
