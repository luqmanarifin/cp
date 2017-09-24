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
  if (__builtin_popcount(mask) > len - now) return 0;
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

  long long ret = 0;
  for (int i = 1; i < sample[0]; i++) {
    ret += dfs(1, 1 << i, 0);
  }
  ret += dfs(1, 1 << sample[0], 1);
  //cout << "debug " << ret << endl;
  for (int i = sample[0] + 1; i < base; i++) {
    ret += dfs(1, 1 << i, 2);
  }

  for (int i = 0; i < pt; i++) {
    dp[a[i]][b[i]][c[i]] = -1;
  }
  pt = 0;
  return ret;
}

int main() {
  memset(dp, -1, sizeof(dp));

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
