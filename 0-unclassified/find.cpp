#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int inf = 1e9;

int dp[N][N];
int p[N][N], q[N][N], h[N][N];
int a, b, c;

int solve(int l, int r) {
  if(dp[l][r] != -1) return dp[l][r];
  if(l == r) return 0;
  if(l > r) return -inf;
  int& ret = dp[l][r] = inf;
  for(int i = l - 1; i < r; i++) {
    for(int j = i; j <= r; j++) {
      int cur[] = {solve(l, i) + a, solve(i + 1, j) + b, solve(j + 1, r) + c};
      int heavy = 0;
      if(cur[1] > cur[heavy]) heavy = 1;
      if(cur[2] > cur[heavy]) heavy = 2;
      if(cur[heavy] <= ret) {
        ret = cur[heavy];
        p[l][r] = i;
        q[l][r] = j;
        h[l][r] = heavy;
      }
    }
  }
  return ret;
}

void backtrack(int l, int r) {
  if(l >= r) {
    puts("dapet");
    return;
  }
  printf("%d %d pilih %d %d pada %d\n", l, r, p[l][r], q[l][r], h[l][r]);
  if(h[l][r] == 0) {
    backtrack(l, p[l][r]);
  } else if(h[l][r] == 1) {
    backtrack(p[l][r] + 1, q[l][r]);
  } else {
    backtrack(q[l][r] + 1, r);
  }
}

int main() {
  int n = 10;
  a = 1;
  b = 2;
  c = 3;
  memset(dp, -1, sizeof(dp));
  printf("solve %d\n", solve(1, n));
  printf("kiri %d\n", solve(1, 4) + a);
  printf("tengah %d\n", solve(1, 7) + b);
  printf("kanan %d\n", solve(1, 13 + c));
  backtrack(1, n);
  return 0;
}
