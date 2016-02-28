#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9;

int dp[1 << 24];
int bef[1 << 24];
int x[24], y[24];
int cen[24];
int bet[24][24];

int dist(int a, int b, int c, int d) {
  return (a - c)*(a - c) + (b - d)*(b - d);
}

void backtrack(int mask) {
  if(mask) backtrack(mask ^ bef[mask]);
  for(int i = 0; i < 31; i++) {
    if(bef[mask] & (1 << i)) {
      printf("%d ", i + 1);
    }
  }
  printf("0 ");
} 

int main() {
  int n, bx, by;
  scanf("%d %d %d", &bx, &by, &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", x + i, y + i);
    cen[i] = dist(x[i], y[i], bx, by);
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      bet[i][j] = dist(x[i], y[i], x[j], y[j]) + cen[i] + cen[j];
    }
  }
  for(int i = 0; i < n; i++) {
    cen[i] *= 2;
  }
  for(int i = 0; i < (1 << 24); i++) {
    dp[i] = inf;
  }
  dp[0] = 0;
  int goal = (1 << n), t, nt;
  for(int mask = 0; mask < goal; mask++) {
    if(dp[mask] == inf) continue;
    for(int i = 0; i < n; i++) if((mask & (1 << i)) == 0) {
      t = dp[mask] + cen[i];
      nt = mask | (1 << i);
      if(t < dp[nt]) {
        dp[nt] = t;
        bef[nt] = (1 << i);
      }
      for(int j = i + 1; j < n; j++) if((mask & (1 << j)) == 0) {
        t = dp[mask] + bet[i][j];
        nt = mask | (1 << i) | (1 << j);
        if(t < dp[nt]) {
          dp[nt] = t;
          bef[nt] = (1 << i) | (1 << j);
        }
      }
      break;
    }
  }
  cout << dp[goal - 1] << endl;
  backtrack(goal - 1); printf("\n");
  return 0;
}