#include <bits/stdc++.h>

using namespace std;

int dp[1005][2005];
int a[1005], n, m;

bool valid(int now) {
  return 1 <= now && now <= n;
}

void backtrack(int it, int pos) {
  if(it == 0) {
    return;
  }
  backtrack(it - 1, dp[it][pos]);
  printf("%d\n", pos);
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
  }
  if(n > 2000) {
    n = 2000;
  }
  for(int i = 1; i <= n; i++) {
    dp[0][i] = 1;
  }
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      if(j == a[i]) {
        continue;
      }
      for(int k = -1; k <= 1; k += 2) {
        if(valid(j + k) && dp[i - 1][j + k]) {
          dp[i][j] = j + k;
        }
      }
    }
  }
  int pos = -1;
  for(int j = 1; j <= n; j++) {
    if(dp[m][j]) {
      pos = j;
    }
  }
  if(pos == -1) {
    puts("menyerah");
    return 0;
  }
  backtrack(m, pos);
  return 0;
}
