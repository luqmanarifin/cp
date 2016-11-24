#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9;
const int N = 4005;

int dp[2500][70][70][2];
int a[N], s[N], n;

int find(int l, int r) {
  return s[r] - s[l - 1]; 
}

int solve(int i, int diff, int k, int st) {
  assert(diff >= 0);
  //printf("%d %d %d %d\n", i, diff, k, st);
  int& ret = dp[i][diff][k][st];
  if (ret != inf) return ret;
  ret = -inf;
  int take;
  if (st == 0) {
    take = i - 1 + diff;
  } else {
    take = i - 1 - diff;
  }
  int j = n - take;
  if (st == 0) {
    if (j - i + 1 >= k) {
      ret = max(ret, find(i, i + k - 1) - solve(i + k, k - diff, k, st ^ 1));
    }
    if (j - i + 1 >= k + 1) {
      ret = max(ret, find(i, i + k) - solve(i + k + 1, k + 1 - diff, k + 1, st ^ 1));
    }
  } else {
    if (j - i + 1 >= k) {
      ret = max(ret, find(j - k + 1, j) - solve(i, k - diff, k, st ^ 1));
    }
    if (j - i + 1 >= k + 1) {
      ret = max(ret, find(j - k, j) - solve(i, k + 1 - diff, k + 1, st ^ 1));
    }
  }
  if (ret == -inf) ret = 0;
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  for (int i = 0; i < 2500; i++) {
    for (int j = 0; j < 70; j++) {
      for (int k = 0; k < 70; k++) {
        dp[i][j][k][0] = dp[i][j][k][1] = inf;
      }
    }
  }
  printf("%d\n", solve(1, 0, 1, 0));
  return 0;
}
